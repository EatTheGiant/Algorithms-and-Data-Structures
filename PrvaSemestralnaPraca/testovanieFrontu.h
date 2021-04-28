#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "structures/priority_queue/priority_queue.h"
#include "structures/priority_queue/priority_queue_list.h"
#include "structures/heap_monitor.h"
//#include "structures/list/list.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;
using namespace structures;
class testovanieFrontu
{
private:


	double merajVlozFront(int prvok, int priorita, PriorityQueue<int>* priorityQueue);
	double* merajZmazFront(PriorityQueue<int>* priorityQueue);
	double* merajUkazFront(PriorityQueue<int>* priorityQueue);
public:

	testovanieFrontu();
	void otestuj(int vloz, int vyber, int ukaz, int pocetOperacii, PriorityQueue<int>* priorityQueue);
	~testovanieFrontu();
};

