#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"
//#include "structures/list/list.h"
#include "structures/heap_monitor.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;
using namespace structures;
class testovanieZoznamu
{
private :
	double merajVloz(int prvok, int index, List<int>* list);
	double merajZmaz(int index, List<int>* list);
	double* merajIndexPrvku(int prvok, List<int>* list);
	double* merajSpristupni(int indexPrvku, List<int>* list);
	double merajNastav(int indexPrvku, int prvok, List<int>* list);
	double merajVlozNaPosledny(int prvok, List<int>* list);

public:
	testovanieZoznamu();
	void otestuj(int vloz, int zmaz, int nastav, int indexPrvku, int pocetOperacii, List<int>* list);
	~testovanieZoznamu();
};

