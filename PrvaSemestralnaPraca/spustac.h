#pragma once
#include <iostream>

#include "testovanieFrontu.h"
#include "testovanieZoznamu.h"
#include "testovanieMatice.h"
#include "testovanieObojZreCykZoz.h"
#include "structures/list/Obojstranne_zretazeny_cyklický_zoznam.h"
#include "structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "structures/priority_queue/heap.h"
#include "structures/priority_queue/priority_queue_two_lists.h"
#include "structures/heap_monitor.h"
using namespace std;

class spustac
{
private:
	void vyberZoznam(bool pokScenar, List<int>* list);

	void vyberFrontu(bool pokScenar, PriorityQueue<int>* queue);

	void vyberMaticu(bool pokScenar, char scenar);

//	void vyberObojZreCykZoz(bool pokScenar, List<int>* obojZreCykZozn);
	//PriorityQueueList<int>* queue = new PriorityQueueSortedArrayList<int>();
	
public:

	spustac();
	void spusti();
	~spustac();
};

