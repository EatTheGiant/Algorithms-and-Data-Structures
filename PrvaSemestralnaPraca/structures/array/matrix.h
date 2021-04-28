#pragma once

#include "..\structure.h"
#include "..\ds_structure_types.h"
#include "../heap_monitor.h"
namespace structures 
{
	template<typename T>
	class Matrix : public Structure
	{
	public:
		virtual Structure* clone() const = 0;
		virtual size_t size() const = 0;
		virtual size_t getPocetRiadkov() const = 0;
		virtual size_t getPocetStlpcov() const = 0;
		Structure& operator=(const Structure& other) override;
		virtual Matrix<T>& operator=(const Matrix<T>& other) = 0;
		virtual T& operator[](const int index) = 0;
		virtual const T operator[](const int index) const = 0;
		virtual void nastav(const size_t indexRiadku, const size_t indexStlpca, const T& initVal) = 0;
		virtual T& spristupni(const size_t indexRiadku, const size_t indexStlpca) = 0;
		Matrix();
	};



	template<typename T>
	inline Structure & Matrix<T>::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Matrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline Matrix<T>::Matrix() :
		Structure()
	{
	}
}