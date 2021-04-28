#include "testovanieObojZreCykZoz.h"
#include "structures/heap_monitor.h"
testovanieObojZreCykZoz::testovanieObojZreCykZoz(int vloz, int zrus, int nastav, int indexPrvku, int pocetOperacii)
{
	this->vloz = vloz;
	this->zrus = zrus;
	this->nastav = nastav;
	this->indexPrvku = indexPrvku;
	this->pocetOperacii = pocetOperacii;
}

void testovanieObojZreCykZoz::otestuj(List<int>* list)
{

}

testovanieObojZreCykZoz::~testovanieObojZreCykZoz()
{
	this->vloz = 0;
	this->zrus = 0;
	this->nastav = 0;
	this->indexPrvku = 0;
	this->pocetOperacii = 0;
}
