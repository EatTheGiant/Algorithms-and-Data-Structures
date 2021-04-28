#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "structures/matrix/matrix.h"
#include "structures/matrix/matrix_nesuv_pam.h"
#include "structures/matrix/matrix_suv_pam.h"
#include "structures/heap_monitor.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;
using namespace structures;
class testovanieMatice
{
private:
	double merajSucet(Matrix<int>* matrix1, Matrix<int>* matrix2, Matrix<int>* matrix3);
	double merajSucin(Matrix<int>* matrix1, Matrix<int>* matrix2, Matrix<int>* matrix3);
public:

	testovanieMatice();
	void otestuj(char scenar, Matrix<int>* matrix1, Matrix<int>* matrix2, Matrix<int>* matrix3, std::ofstream& subor);
	~testovanieMatice();
};