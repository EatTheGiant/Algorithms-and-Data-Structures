#include "testovanieFrontu.h"
#include "structures/heap_monitor.h"
testovanieFrontu::testovanieFrontu()
{

}

testovanieFrontu::~testovanieFrontu()
{
}


void testovanieFrontu::otestuj(int vloz, int vyber, int ukaz, int pocetOperacii, PriorityQueue<int>* priorityQueue) {
	std::ofstream vlozFrontaSubor;
	std::ofstream vyberFrontaSubor;
	std::ofstream ukazFrontaSubor;

	vlozFrontaSubor.open("Output/Fronty/vlozFrontaSubor.csv");
	vyberFrontaSubor.open("Output/Fronty/vyberFrontaSubor.csv");
	ukazFrontaSubor.open("Output/Fronty/ukazFrontaSubor.csv");

	vlozFrontaSubor << "cas operacie" << "," << "vlozene cislo" << "," << "priorita" << "," << "velkost frontu" << ",\n";
	vyberFrontaSubor << "cas operacie" << "," << "vybrane cislo" << "," << "velkost frontu" << ",\n";
	ukazFrontaSubor << "cas operacie" << "," << "cislo" << "," << "velkost frontu" << ",\n";


	int percenta = vloz + vyber + ukaz;
	int percentaOperacii[3] = { vloz, vloz + vyber, vloz + vyber + ukaz };
	double maxPocetOperacii[3] = { pocetOperacii * (double)vloz / percenta,
									pocetOperacii * (double)vyber / percenta,
									pocetOperacii * (double)ukaz / percenta };
	int cislo = 0;
	int pocetCisel[3] = { 0,0,0 };
	double cas = 0;
	

	for (int i = 0; i < pocetOperacii; i++)
	{
		cislo = rand() % percenta + 1;
		//cout << cislo << endl;
		cas = 0;

		if (cislo > 0 && cislo <= percentaOperacii[0] &&
			pocetCisel[0] < maxPocetOperacii[0]) //VLOZ
		{
			int priorita = rand() % 10000;
			cas = merajVlozFront(cislo, priorita, priorityQueue);
			vlozFrontaSubor << cas << "," << cislo << "," << priorita << "," << priorityQueue->size() << ",\n";
			
			pocetCisel[0]++; //PocetVykonanychOperacii
		}
		else if (cislo > percentaOperacii[0] && cislo <= percentaOperacii[1] && //VYBER
			pocetCisel[1] < maxPocetOperacii[1] &&
			priorityQueue->size() > 1 &&
			(pocetCisel[2] == maxPocetOperacii[2] || (pocetCisel[0] + 50) < maxPocetOperacii[0]))
		{
			double* hodnoty = merajZmazFront(priorityQueue);
			double ahaha = *(hodnoty);
			double ahaha2 = *(hodnoty + 1);
			cas = ahaha;
			cislo = ahaha2;
			pocetCisel[1]++;
			vyberFrontaSubor << ahaha << "," << ahaha2 << "," << priorityQueue->size() << ",\n";
		}
		else if (cislo > percentaOperacii[1] && cislo <= percentaOperacii[2] &&
			pocetCisel[2] < maxPocetOperacii[2] &&
			priorityQueue->size() > 0) // UKAZ
		{
			double* hodnoty = merajUkazFront(priorityQueue);
			double ahaha = *(hodnoty);
			double ahaha2 = *(hodnoty + 1);
			cas = ahaha;
			cislo = ahaha2;
			pocetCisel[2]++;
			ukazFrontaSubor << ahaha << "," << ahaha2 << "," << priorityQueue->size() << ",\n";
		}
		
	}

	for (int i = 0; i < 3; i++)
	{
		cout << pocetCisel[i] << endl;
	}
	vlozFrontaSubor.close();
	vyberFrontaSubor.close();
	ukazFrontaSubor.close();
}

double testovanieFrontu::merajVlozFront(int prvok, int priorita, PriorityQueue<int>* priorityQueue)
{

	steady_clock::time_point od_ = steady_clock::now();
	priorityQueue->push(priorita, prvok);
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	return time_span.count();
}

double* testovanieFrontu::merajZmazFront(PriorityQueue<int>* priorityQueue)
{
	int prvokSNajPrio = 0;
	steady_clock::time_point od_ = steady_clock::now();
	prvokSNajPrio = priorityQueue->pop();
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);
	double hodnoty[2] = { time_span.count(), static_cast<double>(prvokSNajPrio) };

	return hodnoty;
}

double* testovanieFrontu::merajUkazFront(PriorityQueue<int>* priorityQueue)
{

	int prvokSNajPrio = 0;
	steady_clock::time_point od_ = steady_clock::now();
	prvokSNajPrio = priorityQueue->peek();
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);
	double hodnoty[2] = { time_span.count(), static_cast<double>(prvokSNajPrio) };

	return hodnoty;
}