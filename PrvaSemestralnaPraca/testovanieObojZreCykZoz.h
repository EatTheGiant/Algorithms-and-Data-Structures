#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "structures/list/list.h"
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"
#include "structures/heap_monitor.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;
using namespace structures;
class testovanieObojZreCykZoz
{
public:
	testovanieObojZreCykZoz(int vloz, int zrus, int nastav, int indexPrvku, int pocetOperacii);
	void otestuj(List<int>* list);
	~testovanieObojZreCykZoz();
private:
	int vloz;
	int zrus;
	int nastav;
	int indexPrvku;
	int pocetOperacii;
};

