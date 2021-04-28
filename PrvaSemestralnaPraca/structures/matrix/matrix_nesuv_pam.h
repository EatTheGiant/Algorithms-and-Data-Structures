#pragma once

#include "matrix.h"
#include "../structure_iterator.h"
#include "../array/array.h"
#include "../heap_monitor.h"
namespace structures
{
	/// <summary> Matica v nesuvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class MatrixNesuvPam : public Matrix<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		MatrixNesuvPam(const size_t pocetRiadkov, const size_t pocetStlpcov, const T& initVal);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> ArrayList, z ktoreho sa prevezmu vlastnosti. </param>
		MatrixNesuvPam(const MatrixNesuvPam<T>& other);

		/// <summary> Destruktor. </summary>
		~MatrixNesuvPam();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat matrixu. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Vrati pocet prvkov v matrixe. </summary>
		/// <returns> Pocet prvkov v matrixe. </returns>
		size_t size() const override;

		/// <summary> Vrati dlzku riadkov v matici. </summary>
		/// <returns> Dlzka riadkov v matici. </returns>
		size_t getPocetRiadkov() const override;

		/// <summary> Vrati pocet stlpcov v matici. </summary>
		/// <returns> Pocet stlpcov v matici. </returns>
		size_t getPocetStlpcov() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Matica, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato matica nachadza po priradeni. </returns>
		Matrix<T>& operator=(const Matrix<T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Matica, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato matica nachadza po priradeni. </returns>
		MatrixNesuvPam<T>& operator=(const MatrixNesuvPam<T>& other);

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do matice. </exception>  
		T& operator[](const int index) override;

		/// <summary> Vrati hodnotou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Hodnota prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do matice. </exception>  
		const T operator[](const int index) const override;

		/// <summary> Zmeni prvok v matici. </summary>
		/// <param name = "data"> Hodnota noveho prvku. </param>

		void nastav(const size_t indexRiadku, const size_t indexStlpca, const T& initVal) override;

		/// <summary> Spristupni prvok v matici. </summary>
		/// <param name = "data"> Hodnota noveho prvku. </param>
		T& spristupni(const size_t indexRiadku, const size_t indexStlpca) override;

	private:
		Array<Array<T>*>* array_;

		size_t pocetRiadkov;
		size_t pocetStlpcov;
	};

	template<typename T>
	inline MatrixNesuvPam<T>::MatrixNesuvPam(const size_t pocetRiadkov, const size_t pocetStlpcov, const T& initVal) :
		Matrix<T>::Matrix(),
		array_(new Array<Array<T>*>(pocetRiadkov)),
		pocetRiadkov(pocetRiadkov),
		pocetStlpcov(pocetStlpcov)
	{
		for (int i = 0; i < pocetRiadkov; i++)
		{
			(*array_)[i] = new Array<T>(pocetStlpcov);
			for (int j = 0; j < pocetStlpcov; j++)
			{
				(*(*array_)[i])[j] = initVal;
			}
		}
	}

	template<typename T>
	inline MatrixNesuvPam<T>::MatrixNesuvPam(const MatrixNesuvPam<T>& other) :
		Matrix<T>::Matrix(),
		array_(new Array<Array<T>*>(other.pocetRiadkov)),
		pocetRiadkov(other.pocetRiadkov),
		pocetStlpcov(other.pocetStlpcov)
	{
		for (int i = 0; i < other.pocetRiadkov; i++)
		{							
			(*array_)[i] = (*other.array_)[i];
			for (int j = 0; j < other.pocetStlpcov; j++)
			{
				(*(*array_)[i])[j] = (*(*other.array_)[i])[j];
			}
		}
	}

	template<typename T>
	inline MatrixNesuvPam<T>::~MatrixNesuvPam()
	{
		for (int i = 0; i < pocetRiadkov; i++)
		{
			delete(*array_)[i];
			(*array_)[i] = nullptr;
		}
		delete array_;
		array_ = nullptr;
		pocetRiadkov = 0;
		pocetStlpcov = 0;
	}

	template<typename T>
	inline Structure* MatrixNesuvPam<T>::clone() const
	{
		return new MatrixNesuvPam<T>(*this);
	}

	template<typename T>
	inline size_t MatrixNesuvPam<T>::size() const
	{
		return pocetRiadkov * pocetStlpcov;
	}

	template<typename T>
	inline size_t MatrixNesuvPam<T>::getPocetRiadkov() const
	{
		return pocetRiadkov;
	}

	template<typename T>
	inline size_t MatrixNesuvPam<T>::getPocetStlpcov() const
	{
		return pocetStlpcov;
	}

	template<typename T>
	inline Matrix<T>& MatrixNesuvPam<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const MatrixNesuvPam<T>&>(other);
		}

		return *this;
	}

	template<typename T>
	inline MatrixNesuvPam<T>& MatrixNesuvPam<T>::operator=(const MatrixNesuvPam<T>& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < this->pocetRiadkov; i++)
			{
				delete (*array_)[i];
			}
			delete array_;

			pocetRiadkov = other.pocetRiadkov;
			pocetStlpcov = other.pocetStlpcov;
			array_ = new Array<Array<T>*>(*(other.array_));
			for (int i = 0; i < other.pocetRiadkov; i++)
			{
				(*array_)[i] = new Array<T>(*((*other.array_)[i]));
			}
		}
		return *this;
	}

	template<typename T>
	inline T& MatrixNesuvPam<T>::operator[](const int index)
	{
		//DSRoutines::rangeCheckExcept(index, size(), "Invalid index in Matrix!");
		//cout << "nesuv pam operator[]" << endl;
		throw 1;
		//return T();
	}

	template<typename T>
	inline const T MatrixNesuvPam<T>::operator[](const int index) const
	{
		//DSRoutines::rangeCheckExcept(index, size(), "Invalid index in Matrix!");
		//cout << "nesuv pam operator[]" << endl;
		return T();
	}

	template<typename T>
	inline void MatrixNesuvPam<T>::nastav(const size_t indexRiadku, const size_t indexStlpca, const T& initVal)
	{
		//DSRoutines::rangeCheckExcept(indexRiadku, pocetRiadkov, "Invalid index (indexRiadku) in Matrix!");
		//DSRoutines::rangeCheckExcept(indexStlpca, pocetStlpcov, "Invalid index (IndexStlpca) in Matrix!");
		int pom = indexRiadku * pocetStlpcov + indexStlpca;
		(*(*array_)[indexRiadku])[indexStlpca] = initVal;
	}

	template<typename T>
	inline T& MatrixNesuvPam<T>::spristupni(const size_t indexRiadku, const size_t indexStlpca)
	{
		//DSRoutines::rangeCheckExcept(indexRiadku, pocetRiadkov, "Invalid index (indexRiadku) in Matrix!");
		//DSRoutines::rangeCheckExcept(indexStlpca, pocetStlpcov, "Invalid index (IndexStlpca) in Matrix!");
		int pom = indexRiadku * pocetStlpcov + indexStlpca;
		return (*(*array_)[indexRiadku])[indexStlpca];
	}
}