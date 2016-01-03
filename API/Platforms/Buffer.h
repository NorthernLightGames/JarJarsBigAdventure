#pragma once

/*
* Platforms\Buffer.h
* -----------------------
* Author: Valdemar Melin
* Created on: 3 dec 2016
*
*/

namespace Platforms {

	template<typename T>
	struct buffer {

		explicit Buffer(int n):length(n) {

		}

		virtual T operator[](int n) const;
		virtual T& operator[](int n);

		const int length;

	protected:
		T* data;
	};

	template<typename T>
	inline T buffer<T>::operator[](int i) const {
		return data[n];
	}

	template<typename T>
	inline T & buffer<T>::operator[](int n){
		return data[n];
	}

	typedef buffer<byte>	byte_buffer;
	typedef buffer<int>		int_buffe;
	typedef buffer<scalar>	scalar_buffer;
}