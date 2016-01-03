#pragma once
/*
* Platforms\Array.h
* -----------------------
* Author: Valdemar Melin
* Created on: 31 dec 2015
*
* Declares the Array class.
*/

#include <Platforms.h>


#ifdef SOMEDAY_I_WILL_MAKE_MY_OWN_ARRAY_CLASS
namespace Platforms {
	
	template<typename T>
	PLAPI struct Array {
		Array(unsigned int size = 0, bool resize = true): resize(resize), elem_size(sizeof(T)) {
			elem_size = sizeof(T);
			min_increase = 10;
			increase_amount = 0.2f;
		};

		virtual ~Array() {
			delete[] data;
		}

		inline unsigned int Size() const {
			return data_size / elem_size;
		}

		inline void Add(const T& elem) {

		}

		inline void Insert(const T& elem, int pos) {

		}

		inline void Remove(int i) {

		}

		inline int Pack() {
			
		}

		inline T operator [] (int i) const {
			if (i >= size() || i < 0) return nullptr;
			return (T) data[i*elem_size];
		}

	private:
		float increase_amount;
		int min_increase;
		void* data;
		int data_size;
		const int elem_size;
		const bool resize;
	};
	*/
}
#else
#include <vector>

namespace Platforms {

	template<typename T>
	struct Array : public std::vector<T> { };
}
#endif