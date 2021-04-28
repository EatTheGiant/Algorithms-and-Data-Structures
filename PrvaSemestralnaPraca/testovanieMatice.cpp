#include "testovanieMatice.h"
#include "structures/heap_monitor.h"
double testovanieMatice::merajSucet(Matrix<int>* matrix1, Matrix<int>* matrix2, Matrix<int>* matrix3)
{
	steady_clock::time_point od_ = steady_clock::now();
	for (int i = 0; i < matrix1->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < matrix1->getPocetStlpcov(); j++)
		{
			matrix3->nastav(i, j, matrix1->spristupni(i, j) + matrix2->spristupni(i, j));
		}
	}
	steady_clock::time_point do_ = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	return time_span.count();
}

double testovanieMatice::merajSucin(Matrix<int>* matrix1, Matrix<int>* matrix2, Matrix<int>* matrix3)
{
	steady_clock::time_point od_ = steady_clock::now();
	int cislo = 0;
	for (int i = 0; i < matrix1->getPocetRiadkov(); i++) {
		for (int j = 0; j < matrix2->getPocetStlpcov(); j++) {
			for (int k = 0; k < matrix2->getPocetRiadkov(); k++)
			{
				matrix3->nastav(i,j, matrix3->spristupni(i, j) + matrix1->spristupni(i, k) * matrix2->spristupni(k, j));
			}
			//cout << matrix3->spristupni(i, j) << " ";
		}
		//cout << endl;

	}
	steady_clock::time_point do_ = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(do_ - od_);

	for (int i = 0; i < matrix1->getPocetRiadkov(); i++) {
		for (int j = 0; j < matrix2->getPocetStlpcov(); j++) {
		}
	}
	return time_span.count();
}

testovanieMatice::testovanieMatice()
{
}

void testovanieMatice::otestuj(char scenar, Matrix<int>* matrix1, Matrix<int>* matrix2, Matrix<int>* matrix3, std::ofstream& subor)
{
	

	double cas = 0.0;
		
		if (scenar == 'A')
		{
			cas = merajSucet(matrix1, matrix2, matrix3);
			subor << cas << "," << matrix3->getPocetRiadkov() << "," << matrix3->getPocetStlpcov() << ",\n";

		}
		else if (scenar == 'B')
		{
			cas = merajSucin(matrix1, matrix2, matrix3);
			subor << cas << "," << matrix3->getPocetRiadkov() << "," << matrix3->getPocetStlpcov() << ",\n";
		}
		else {
			cout << "Chyba v Metrixe." << endl;
		}
	
	delete matrix1;
	matrix1 = nullptr;
	delete matrix2;
	matrix2 = nullptr;
	delete matrix3;
	matrix3 = nullptr;
}

testovanieMatice::~testovanieMatice()
{
}
