#include "testovanieZoznamu.h"
#include "structures/heap_monitor.h"
testovanieZoznamu::testovanieZoznamu()
{
}

void testovanieZoznamu::otestuj(int vloz, int zmaz, int nastav, int dajIndexPrvku, int pocetOperacii, List<int>* list)
{

	std::ofstream vlozNaPrvyPrvok;
	std::ofstream vlozNaIndexPrvok;
	std::ofstream vlozNaPoslednyPrvok;
	std::ofstream zmazPrvyPrvok;
	std::ofstream zmazNaIndexePrvok;
	std::ofstream zmazPoslednyPrvok;
	std::ofstream nastavPrvok;
	std::ofstream spristupniPrvok;
	std::ofstream indexPrvkuSubor;
	vlozNaPrvyPrvok.open("Output/Zoznamy/vlozNaPrvyPrvok.csv");
	vlozNaIndexPrvok.open("Output/Zoznamy/vlozNaIndexPrvok.csv");
	vlozNaPoslednyPrvok.open("Output/Zoznamy/vlozNaPoslednyPrvok.csv");
	zmazPrvyPrvok.open("Output/Zoznamy/zmazPrvyPrvok.csv");
	zmazNaIndexePrvok.open("Output/Zoznamy/zmazNaIndexePrvok.csv");
	zmazPoslednyPrvok.open("Output/Zoznamy/zmazPoslednyPrvok.csv");
	nastavPrvok.open("Output/Zoznamy/nastavPrvok.csv");
	spristupniPrvok.open("Output/Zoznamy/spristupniPrvok.csv");
	indexPrvkuSubor.open("Output/Zoznamy/indexPrvkuSubor.csv");

	vlozNaPrvyPrvok << "cas operacie" << "," << "vlozene cislo" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	vlozNaIndexPrvok << "cas operacie" << "," << "vlozene cislo" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	vlozNaPoslednyPrvok << "cas operacie" << "," << "vlozene cislo" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	zmazPrvyPrvok << "cas operacie" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	zmazNaIndexePrvok << "cas operacie" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	zmazPoslednyPrvok << "cas operacie" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	nastavPrvok << "cas operacie" << "," << "cislo" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	spristupniPrvok << "cas operacie" << "," << "cislo na indexe" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";
	indexPrvkuSubor << "cas operacie" << "," << "vlozene cislo" << "," << "index prvku" << "," << "dlzka zoznamu" << ",\n";


	//LinkedList<int>* linkedList = new LinkedList<int>();
	//ArrayList<int>* arrayList = new ArrayList<int>();



	int percenta = vloz + zmaz + nastav + dajIndexPrvku;
	int percentaOperacii[4] = { vloz, vloz + zmaz, vloz + zmaz + nastav, vloz + zmaz + nastav + dajIndexPrvku };
	double maxPocetOperacii[4] = { pocetOperacii * (double)vloz / percenta,
									pocetOperacii * (double)zmaz / percenta,
									pocetOperacii * (double)nastav / percenta,
									pocetOperacii * (double)dajIndexPrvku / percenta };

	int cislo = 0;
	int pocetCisel[4] = { 0,0,0,0 };
	int indexPrvku = 0;
	double cas = 0;
	//int pocetCiselZoznamu = 0;



	/*
		20
		40 = 20 + 20
		90 = 50 + 20 + 20
		100 = 10 + 50 + 20 + 20
	*/

	for (int i = 0; i < pocetOperacii; i++)
	{
		cislo = rand() % percenta + 1;
		indexPrvku = 0;
		cas = 0;

		if (cislo > 0 && cislo <= percentaOperacii[0] &&
			pocetCisel[0] < maxPocetOperacii[0]) //VLOZ
		{

			int random = rand() % 3 + 1;

			if (random == 1)
			{
				cas = merajVloz(cislo, indexPrvku, list); //VlozPrvy
				vlozNaPrvyPrvok << cas << "," << cislo << "," << indexPrvku << "," << list->size() << ",\n"; //cas, indexPrvku, dlzkaZoznamu
			}
			else if (random == 2)
			{
				indexPrvku = 0;

				if (list->size() > 0)
				{
					indexPrvku = rand() % list->size();

				}

				cas = merajVloz(cislo, indexPrvku, list); // VlozNaIndex
				vlozNaIndexPrvok << cas << "," << cislo << "," << indexPrvku << "," << list->size() << ",\n"; //cas, indexPrvku, dlzkaZoznamu
			}
			else if (random == 3)
			{
				indexPrvku = list->size();
				cas = merajVlozNaPosledny(cislo, list); //VlozPosledny
				vlozNaPoslednyPrvok << cas << "," << cislo << "," << indexPrvku << "," << list->size() << ",\n"; //cas, indexPrvku, dlzkaZoznamu
			}

			pocetCisel[0]++; //PocetVykonanychOperacii
		}

		else if (cislo > percentaOperacii[0] && cislo <= percentaOperacii[1] &&
			pocetCisel[1] < maxPocetOperacii[1] &&
			list->size() > 0 &&
			(
				(pocetCisel[2] == maxPocetOperacii[2] && //5000
					pocetCisel[3] == maxPocetOperacii[3]) ||//1000
				(pocetCisel[0] + 50) < maxPocetOperacii[0]
				)
			) //ZMAZ
		{

			int random = rand() % 3 + 1;

			if (random == 1)
			{
				cas = merajZmaz(indexPrvku, list); //ZrusPrvy
				zmazPrvyPrvok << cas << "," << indexPrvku << "," << list->size() << ",\n";
			}
			else if (random == 2)
			{
				indexPrvku = 0;

				if (list->size() > 1)
				{
					indexPrvku = rand() % (list->size() - 1);
				}
				cas = merajZmaz(indexPrvku, list); // ZrusNaIndexe
				zmazNaIndexePrvok << cas << "," << indexPrvku << "," << list->size() << ",\n";
			}
			else if (random == 3)
			{
				indexPrvku = list->size() - 1;
				cas = merajZmaz(indexPrvku, list); //ZrusPosledny
				zmazPoslednyPrvok << cas << "," << indexPrvku << "," << list->size() << ",\n";
			}

			pocetCisel[1]++; //pocetZmazanychCisel

		}
		else if (cislo > percentaOperacii[1] && cislo <= percentaOperacii[2] &&
			pocetCisel[2] < maxPocetOperacii[2] &&
			list->size() > 0) // NASTAV
		{

			int random = rand() % 2 + 1;
			if (random == 1)
			{

				indexPrvku = 0;

				if (list->size() > 1)
				{
					indexPrvku = rand() % (list->size() - 1);
				}

				double* hodnoty = merajSpristupni(indexPrvku, list); // tu by bolo dobre zapisovat cas << indexPrvku << getnute cislo << pocetCiselZoznamu
				double ahaha = *(hodnoty);
				double ahaha2 = *(hodnoty + 1);
				cas = ahaha;
				cislo = ahaha2;
				//cout << ahaha << " dada " << ahaha2 << endl;
				spristupniPrvok << ahaha << "," << ahaha2 << "," << indexPrvku << "," << list->size() << ",\n";
			}
			else if (random == 2)
			{
				indexPrvku = 0;

				if (list->size() > 1)
				{
					indexPrvku = rand() % (list->size() - 1);
				}

				cas = merajNastav(indexPrvku, cislo, list);
				nastavPrvok << cas << "," << cislo << "," << indexPrvku << "," << list->size() << ",\n";
			}

			pocetCisel[2]++;
		}
		else if (cislo > percentaOperacii[2] && cislo <= percentaOperacii[3] &&
			pocetCisel[3] < maxPocetOperacii[3] &&
			list->size() > 0) // INDEXPRVKU
		{
			int x = (*list)[rand() % list->size()];
			//int data = list->getIndexOf(x);
			double* hodnoty = merajIndexPrvku(x, list);  //IndexPrvku
			double ahaha = *(hodnoty);//cas operacie
			double ahaha2 = *(hodnoty + 1); // hodnota prvku
			cas = ahaha;
			cislo = ahaha2;
			//cout << ahaha << " dada " << ahaha2 << endl;
			indexPrvkuSubor << ahaha << "," << cislo << "," << ahaha2 << "," << list->size() << ",\n";

			pocetCisel[3]++;
		}
		else {
			//cout << cislo <<  "Toto nebere" << endl;  //pocetCisel[0] << " " << pocetCisel[1] << " " << pocetCisel[2] << " " << pocetCisel[3] << endl;
			//cout << "vloz..." << vloz << " " << zmaz << " " << nastav << " " << dajIndexPrvku << " " << 100000 << endl;
			//cout << percenta << "pocetCiselZoznamu" << list->size() << endl;
			pocetOperacii++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << pocetCisel[i] << endl;
	}


	vlozNaPrvyPrvok.close();
	vlozNaIndexPrvok.close();
	vlozNaPoslednyPrvok.close();
	zmazPrvyPrvok.close();
	zmazNaIndexePrvok.close();
	zmazPoslednyPrvok.close();
	nastavPrvok.close();
	spristupniPrvok.close();
	indexPrvkuSubor.close();
}

testovanieZoznamu::~testovanieZoznamu()
{
}

double testovanieZoznamu::merajVloz(int prvok, int index, List<int>* list)
{
	steady_clock::time_point od_;
	steady_clock::time_point do_;

	od_ = steady_clock::now();
	list->insert(prvok, index);
	do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	return time_span.count();
}

double testovanieZoznamu::merajZmaz(int index, List<int>* list)
{

	steady_clock::time_point od_ = steady_clock::now();
	list->removeAt(index);
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	return time_span.count();
}

double* testovanieZoznamu::merajIndexPrvku(int prvok, List<int>* list) //
{
	int index;
	steady_clock::time_point od_ = steady_clock::now();
	index = list->getIndexOf(prvok);
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);
	double hodnoty[2] = { time_span.count(), static_cast<double>(index) };
	//cout << time_span.count() << "   " << index << endl;
	//double* poleDoublov = new double[2];

	//(*poleDoublov)[0] = time_span.count();
	//(*poleDoublov)[1] = static_cast<double>(index);
	return hodnoty;
}

double* testovanieZoznamu::merajSpristupni(int indexPrvku, List<int>* list) {
	int prvok;
	//cout << "spristupni, index prvku" << indexPrvku << endl;
	steady_clock::time_point od_ = steady_clock::now();
	prvok = (*list)[indexPrvku];
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);
	double hodnoty[2] = { time_span.count(), static_cast<double>(prvok) };

	return hodnoty;
}

double testovanieZoznamu::merajNastav(int indexPrvku, int prvok, List<int>* list) {
	//cout << "VelkostZoznamu " << list->size() << endl;
	//cout << "Prvok " << (*list)[indexPrvku] << " menim na " << prvok << " na indexe " << indexPrvku << endl;
	//cout << "nastav, index prvku" << indexPrvku << endl;
	steady_clock::time_point od_ = steady_clock::now();
	(*list)[indexPrvku] = prvok;
	steady_clock::time_point do_ = steady_clock::now();
	//cout << endl << "Novy zoznam" << endl;
	//cout << "Novy Prvok " << (*list)[indexPrvku] << "na indexe " << indexPrvku << endl;
	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	return time_span.count();
}

double testovanieZoznamu::merajVlozNaPosledny(int prvok, List<int>* list) {
	steady_clock::time_point od_ = steady_clock::now();
	list->add(prvok);
	steady_clock::time_point do_ = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	return time_span.count();
}
