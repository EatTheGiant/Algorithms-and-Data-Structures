#pragma once

#include "matrix.h"
#include "../structure_iterator.h"
#include "../array/array.h"
#include "../heap_monitor.h"
namespace structures
{

	/// <summary> Zoznam implementovany polom. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
	template<typename T>
	class MatrixSuvPam : public Matrix<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		MatrixSuvPam(const size_t pocetRiadkov, const size_t pocetStlpcov, const T& initVal);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> MatrixSuvPam, z ktoreho sa prevezmu vlastnosti. </param>
		MatrixSuvPam(const MatrixSuvPam<T>& other);

		/// <summary> Destruktor. </summary>
		~MatrixSuvPam();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat zoznamu. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Vrati pocet prvkov v zozname. </summary>
		/// <returns> Pocet prvkov v zozname. </returns>
		size_t size() const override;


		/// <summary> Vrati dlzku riadkov v matici. </summary>
		/// <returns> Dlzka riadkov v matici. </returns>
		size_t getPocetRiadkov() const override;

		/// <summary> Vrati pocet stlpcov v matici. </summary>
		/// <returns> Pocet stlpcov v matici. </returns>
		size_t getPocetStlpcov() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zoznam, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zoznam nachadza po priradeni. </returns>
		Matrix<T>& operator=(const Matrix<T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zoznam, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zoznam nachadza po priradeni. </returns>
		MatrixSuvPam<T>& operator=(const MatrixSuvPam<T>& other);

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		T& operator[](const int index) override;

		/// <summary> Vrati hodnotou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Hodnota prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		const T operator[](const int index) const override;

		/// <summary> Zmeni prvok v matici. </summary>
		/// <param name = "data"> Hodnota noveho prvku. </param>

		void nastav(const size_t indexRiadku, const size_t indexStlpca, const T& initVal) override;

		/// <summary> Spristupni prvok v matici. </summary>
		/// <param name = "data"> Hodnota noveho prvku. </param>
		T& spristupni(const size_t indexRiadku, const size_t indexStlpca) override;

	private:
		Array<T>* array_;

		size_t pocetRiadkov;
		size_t pocetStlpcov;
		
	};

	template<typename T>
	inline MatrixSuvPam<T>::MatrixSuvPam(const size_t pocetRiadkov, const size_t pocetStlpcov, const T& initVal) :
		Matrix<T>(),
		array_(new Array<T>(pocetRiadkov* pocetStlpcov)),
		pocetRiadkov(pocetRiadkov),
		pocetStlpcov(pocetStlpcov)
	{
		for (int i = 0; i < (pocetRiadkov * pocetStlpcov); i++)
		{
			(*array_)[i] = initVal;
		}
	}

	template<typename T>
	inline MatrixSuvPam<T>::MatrixSuvPam(const MatrixSuvPam<T>& other) :
		Matrix<T>::Matrix(),
		array_(new Array<T>(*other.array_)),
		pocetRiadkov(other.pocetRiadkov),
		pocetStlpcov(other.pocetStlpcov)
	{
		for (int i = 0; i < (other.pocetRiadkov * other.pocetStlpcov); i++)
		{
			(*array_)[i] = (*other.array_)[i];
		}
		//array_ = new  Array<T>(*(other.array_));
	}

	template<typename T>
	inline MatrixSuvPam<T>::~MatrixSuvPam()
	{
		pocetRiadkov = 0;
		pocetStlpcov = 0;
		delete array_;
		array_ = nullptr;
	}

	template<typename T>
	inline Structure* MatrixSuvPam<T>::clone() const
	{
		return new MatrixSuvPam<T>(*this);
	}

	template<typename T>
	inline size_t MatrixSuvPam<T>::size() const
	{
		return pocetRiadkov * pocetStlpcov;
	}

	template<typename T>
	inline size_t MatrixSuvPam<T>::getPocetRiadkov() const
	{
		return pocetRiadkov;
	}

	template<typename T>
	inline size_t MatrixSuvPam<T>::getPocetStlpcov() const
	{
		return pocetStlpcov;
	}

	template<typename T>
	inline Matrix<T>& MatrixSuvPam<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const MatrixSuvPam<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline MatrixSuvPam<T>& MatrixSuvPam<T>::operator=(const MatrixSuvPam<T>& other)
	{
		if (this != &other)
		{
			pocetRiadkov = other.pocetRiadkov;
			pocetStlpcov = other.pocetStlpcov;

			delete array_;
			array_ = new  Array<T>(*(other.array_));

		}
		return *this;
	}

	template<typename T>
	inline T& MatrixSuvPam<T>::operator[](const int index)
	{
		//DSRoutines::rangeCheckExcept(index, size(), "Invalid index in Matrix!");
		return (*array_)[index];
	}

	template<typename T>
	inline const T MatrixSuvPam<T>::operator[](const int index) const
	{
		//DSRoutines::rangeCheckExcept(index, size(), "Invalid index in Matrix!");
		return (*array_)[index];
	}

	

	template<typename T>
	inline void MatrixSuvPam<T>::nastav(const size_t indexRiadku, const size_t indexStlpca, const T& initVal)
	{
		//DSRoutines::rangeCheckExcept(indexRiadku, pocetRiadkov, "Invalid index (indexRiadku) in Matrix!");
		//DSRoutines::rangeCheckExcept(indexStlpca, pocetStlpcov, "Invalid index (IndexStlpca) in Matrix!");
		int pom = indexRiadku * pocetStlpcov + indexStlpca;
		(*array_)[pom] = initVal;
	}

	template<typename T>
	inline T& MatrixSuvPam<T>::spristupni(const size_t indexRiadku, const size_t indexStlpca)
	{
		//DSRoutines::rangeCheckExcept(indexRiadku, pocetRiadkov, "Invalid index (indexRiadku) in Matrix!");
		//DSRoutines::rangeCheckExcept(indexStlpca, pocetStlpcov, "Invalid index (IndexStlpca) in Matrix!");
		int pom = indexRiadku * pocetStlpcov + indexStlpca;
		return (*array_)[pom];
	}

}