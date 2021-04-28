#include "spustac.h"
#include "structures/heap_monitor.h"
void spustac::vyberZoznam(bool pokScenar, List<int>* list)
{
	testovanieZoznamu testovanie;
	while (pokScenar)
	{
		char scenar = 'A';
		cout << "Vyberte si scenar A, B, C (V pre vlastny scenar, S pre vyber ADT)." << endl;
		cin >> scenar;
		switch (scenar)
		{
		case 'A':
			testovanie.otestuj(20, 20, 50, 10, 100000, list);
			break;
		case 'B':
			testovanie.otestuj(35, 35, 20, 10, 100000, list);
			break;
		case 'C':
			testovanie.otestuj(45, 45, 5, 5, 100000, list);
			break;
		case 'S':
			pokScenar = false;
			break;
		default:
			cout << "Zadali ste nespravny scenar." << endl;
			break;
		case 'V':
			int vloz = 0;
			int zrus = 0;
			int nastav = 0;
			int indexPrvku = 0;
			int pocetOperacii = 1;
			cout << "Vloz % -> ";
			cin >> vloz;

			cout << endl << "Zrus % -> ";
			cin >> zrus;

			cout << endl << "Nastav % -> ";
			cin >> nastav;

			cout << endl << "IndexPrvku % -> ";
			cin >> indexPrvku;

			cout << endl << "PocetOperacii % -> ";
			cin >> pocetOperacii;

			cout << endl;
			testovanie.otestuj(vloz, zrus, nastav, indexPrvku, pocetOperacii, list);
			break;
		}
	}
	list->clear();
	delete list;
	list = nullptr;
}

void spustac::vyberFrontu(bool pokScenar, PriorityQueue<int>* queue)
{
	testovanieFrontu testovanie;
	while (pokScenar)
	{
		char scenar = 'A';
		cout << "Vyberte si scenar A, B, C (V pre vlastny scenar, S pre vyber ADT)." << endl;
		cin >> scenar;
		switch (scenar)
		{
		case 'A':
			testovanie.otestuj(35, 35, 30, 100000, queue);
			break;
		case 'B':
			testovanie.otestuj(50, 30, 20, 100000, queue);
			break;
		case 'C':
			testovanie.otestuj(70, 25, 5, 100000, queue);
			break;
		case 'S':
			pokScenar = false;
			break;
		default:
			cout << "Zadali ste nespravny scenar." << endl;
			break;
		case 'V':
			int vloz = 0;
			int vyber = 0;
			int ukaz = 0;
			int pocetOperacii = 1;
			cout << "Vloz % -> ";
			cin >> vloz;

			cout << endl << "Vyber % -> ";
			cin >> vyber;

			cout << endl << "Ukaz% -> ";
			cin >> ukaz;

			cout << endl << "PocetOperacii % -> ";
			cin >> pocetOperacii;

			cout << endl;
			testovanie.otestuj(vloz, vyber, ukaz, pocetOperacii, queue);
			break;
		}
	}
}

void spustac::vyberMaticu(bool pokScenar, char scenar) {
	testovanieMatice testovanie;
	while (pokScenar)
	{
		char druhMatice = 'S';
		int rozmer1 = 0;
		int rozmer2 = 0;
		int initVal = 0;
		cout << "Vyberte si Maticu v S (Suvislej pamati), N (Nesuvislej pamati), X (pre vyber ADT)." << endl;
		cin >> druhMatice;

		std::ofstream sucetMaticeSubor;
		std::ofstream sucinMaticeSubor;

		sucetMaticeSubor.open("Output/Matice/sucetMaticeSubor.csv");
		sucinMaticeSubor.open("Output/Matice/sucinMaticeSubor.csv");

		sucetMaticeSubor << "cas operacie" << "," << "pocetRiadkov" << "," << "pocetStlpcov" << ",\n";
		sucinMaticeSubor << "cas operacie" << "," << "pocetRiadkov" << "," << "pocetStlpcov" << ",\n";

		for (int i = 1; i < 81; i++)
		{
				rozmer1 = i;
				rozmer2 = 7 * i;
				initVal = 5;
				if (scenar == 'A')
				{
					switch (druhMatice)
					{
					case 'S':
						testovanie.otestuj( scenar, 
											new MatrixSuvPam<int>(rozmer1, rozmer2, initVal), 
											new MatrixSuvPam<int>(rozmer1, rozmer2, initVal),
											new MatrixSuvPam<int>(rozmer1, rozmer2, 0), sucetMaticeSubor);
						break;
					case 'N':
						testovanie.otestuj( scenar,
											new MatrixNesuvPam<int>(rozmer1, rozmer2, initVal),
											new MatrixNesuvPam<int>(rozmer1, rozmer2, initVal),
											new MatrixNesuvPam<int>(rozmer1, rozmer2, 0), sucetMaticeSubor);
						break;
					case 'X':
						pokScenar = false;
						break;
					default:
						cout << "Zadali ste nespravnu maticu." << endl;
						break;
					}
				}
				else if (scenar == 'B')
				{
					switch (druhMatice)
					{
					case 'S':
						testovanie.otestuj( scenar,
											new MatrixSuvPam<int>(rozmer1, rozmer2, initVal),
											new MatrixSuvPam<int>(rozmer2, rozmer1, initVal),
											new MatrixSuvPam<int>(rozmer1, rozmer1, 0), sucinMaticeSubor);
						break;
					case 'N':
						testovanie.otestuj( scenar,
											new MatrixNesuvPam<int>(rozmer1, rozmer2, initVal),
											new MatrixNesuvPam<int>(rozmer2, rozmer1, initVal),
											new MatrixNesuvPam<int>(rozmer1, rozmer1, 0), sucinMaticeSubor);
						break;
					case 'X':
						pokScenar = false;
						break;
					default:
						cout << "Zadali ste nespravnu maticu." << endl;
						break;
					}
				}
				cout << "spravil som maticu " << endl;
			}
		sucinMaticeSubor.close();
		sucetMaticeSubor.close();
		}
}

spustac::spustac()
{
}

void spustac::spusti()
{

	char ADT = 'Z';
	bool pokADT = true;
	srand(time(NULL));

	

	while (pokADT)
	{
		cout << "Vyberte si ADT Z, Q, M (K pre koniec)." << endl;

		cin >> ADT;
		bool pokracuj = true;
		switch (ADT)
		{

		case 'Z':
			
			while (pokracuj)
			{
				char druhZoznamu = 'A';
				
				cout << "Vyberte si zoznam A (Array List), L(Linked List), O (ObojZretLinkedList) (X pre vyber ADT)." << endl;
				cin >> druhZoznamu;
				switch (druhZoznamu)
				{
				case 'A':
					vyberZoznam(true, new ArrayList<int>());
					break;
				case 'L':
					vyberZoznam(true, new LinkedList<int>());
					break;
				case 'O':
					vyberZoznam(true, new ObojZretLinkedList<int>());
					break;
				case 'X':
					pokracuj = false;
					break;
				default:
					cout << "Zadali ste nespravny zoznam." << endl;
					break;
				}
			}
			break;

		case 'Q': //Prioritny front
			while (pokracuj)
				
			{
				char druhFrontu = 'Z';
				PriorityQueue<int>* queue = new PriorityQueueSortedArrayList<int>();

				cout << "Vyberte si druh frontu Z (Zoznam implementovany polom s prioritami), H (Lavostranna halda), D (PriorityQueueTwoLists), (X pre vyber ADT)." << endl;
				cin >> druhFrontu;

				if (druhFrontu == 'Z')
				{
					queue->clear();
					delete queue;
					queue = nullptr;
					queue = new PriorityQueueSortedArrayList<int>();
					vyberFrontu(true, queue);
				}
				else if (druhFrontu == 'H') {
					queue->clear();
					delete queue;
					queue = nullptr;
					queue = new Heap<int>();
					vyberFrontu(true, queue);
				}
				else if (druhFrontu == 'D') {
					queue->clear();
					delete queue;
					queue = nullptr;
					queue = new PriorityQueueTwoLists<int>();
					vyberFrontu(true, queue);
				}
				else if (druhFrontu == 'X')
				{
					pokracuj = false;
				}
				else
				{
					cout << "Zadali ste nespravny front." << endl;
				}
				queue->clear();
				delete queue;
				queue = nullptr;
			}
			break;
		case 'M': //Matica
			while (pokracuj)
			{
				
				char scenar = 'A';
				cout << "Vyberte si scenar A, B (V pre vlastny scenar, S pre vyber ADT)." << endl;
				cin >> scenar;
				switch (scenar)
				{
				case 'A':
					vyberMaticu(true, scenar);
					break;
				case 'B':
					vyberMaticu(true, scenar);
					break;
				case 'S':
					pokracuj = false;
					break;
				default:
					cout << "Zadali ste nespravny scenar." << endl;
					break;
				}
			}

			break;
		case 'B':
			cout << "Zatial nefunkcne." << endl;

			break;
		case 'K':
			pokADT = false;
			break;
		default:
			cout << "Zadali ste nespravny scenar." << endl;
			break;
		}
	}
}

spustac::~spustac()
{

}
