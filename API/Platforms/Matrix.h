#pragma once

/*
 * Platforms\Matrix.h
 * -----------------------
 * Author: Valdemar Melin
 * Created on: 31 dec 2015
 *
 * Linear algebra header.
 */

#include <Platforms.h>
#include <cmath>
#include <iostream>

namespace Platforms {

	typedef float scalar;

	struct PLAPI matrix {

	public:

		inline static matrix Square(const int n, scalar* elements = nullptr) {
			return matrix(n, n, elements);
		}

		inline static matrix Row(const int n, scalar* elements = nullptr) {
			return matrix(1, n, elements);
		}

		inline static matrix Col(const int n, scalar* elements = nullptr) {
			return matrix(n, 1, elements);
		}

		inline static matrix Identity(const int n) {
			scalar* elements = new scalar[n*n]();
			for (int i = 0; i < n; i++) {
				elements[i*n + i] = 1;
			}
			return matrix(n, n, elements);
			delete[] elements;
		}

	public:

		/*
		 *
		 * Creates a matrix with <rows> rows and <cols> columns.
		 */
		matrix(int rows, int cols, const scalar* elements = nullptr) :
			n_rows(rows),
			n_cols(cols),
			data(new scalar[rows*cols]())
		{
			if (elements) {
				for (int i = 0; i < size(); i++) {
					data[i] = elements[i];
				}
			}
		}

		matrix(const matrix& m) : matrix(m.n_rows, m.n_cols) {
			for (int i = 0; i < size(); i++) {
				data[i] = m[i];
			}
		}

		virtual ~matrix() {
			delete[] data;
		}

		inline int size() const {
			return n_cols*n_rows;
		}

		inline int rows() const {
			return n_rows;
		}

		inline int cols() const {
			return n_cols;
		}

		matrix T() const;
		//scalar det() const;
		//scalar tr() const;

		// Index starts from 0
		inline scalar& operator [] (const int n) {
			return data[n];
		}

		// Index starts from 0
		inline scalar& operator () (const int n) {
			return (*this)[n];
		}

		// Index starts from 0
		inline scalar& operator () (const int r, const int c) {
			return (*this)[r*n_cols + c];
		}

		// Index starts from 0
		inline scalar operator [] (const int n) const {
			return data[n];
		}

		// Index starts from 0
		inline scalar operator () (const int n) const {
			return (*this)[n];
		}

		// Index starts from 0
		inline scalar operator () (const int r, const int c) const {
			return (*this)[r*n_cols + c];
		}

		inline operator const scalar* () const {
			return data;
		}

		inline operator scalar* () {
			return data;
		}

		matrix& operator=(const matrix& m);

	private:
		int n_rows;
		int n_cols;
		scalar* data;
	};

	/*
	 *
	 * Performs matrix addition.
	 * Note: the matrices must have same number of rows and columns.
	 */
	PLAPI matrix operator + (const matrix& a, const matrix& b);
	PLAPI matrix& operator += (matrix& a, const matrix& b);

	/*
	 *
	 * Performs matrix subtraction.
	 * Note: the matrices must have same number of rows and columns.
	 */
	PLAPI matrix operator - (const matrix& a, const matrix& b);
	PLAPI matrix& operator -= (matrix& a, const matrix& b);

	/*
	 *
	 * Performs matrix multiplication by scalar.
	 */
	PLAPI matrix operator * (const matrix& a, const scalar k);
	inline matrix operator *(const scalar k, const matrix& a) { return a * k; }
	PLAPI matrix& operator *= (matrix& a, const scalar k);

	/*
	 *
	 * Performs element-wise multiplication.
	 * Note: Same dimensions for <a> and <b> required.
	 */
	PLAPI matrix operator ^ (const matrix& a, const matrix& b);
	PLAPI matrix& operator ^= (matrix& a, const matrix& b);

	matrix PLAPI mpow(const matrix& a, scalar s);

	/*
	 *
	 * Performs matrix multiplication.
	 * Note: The number of columns in <a> must equal the number of rows in <b>.
	 */
	PLAPI matrix operator * (const matrix& a, const matrix& b);

	//inline float det(const Matrix& m) { return m.det(); }
	//inline float tr(const Matrix& m) { return m.tr(); }

	PLAPI std::ostream& operator << (std::ostream& os, const matrix& m);
	PLAPI std::wostream& operator << (std::wostream& os, const matrix& m);


	/*
	 * Column matrix aka column vector.
	 */
	struct PLAPI vector {
	public:
		vector(int n, const scalar* elements = nullptr): d(n), data(new float[n]()) {
			if (elements) {
				for (int i = 0; i < n; i++) {
					data[i] = elements[i];
				}
			}
		}

		virtual ~vector() {
			delete[] data;
		}

		// Index starts from 0
		inline scalar& operator[] (int x) {
			return data[x];
		}

		// Index starts from 0
		inline scalar operator[] (int x) const {
			return data[x];
		}

		// Index starts from 0
		inline scalar& operator() (int x) {
			return data[x];
		}

		// Index starts from 0
		inline scalar operator() (int x) const {
			return data[x];
		}

		inline operator const scalar* () const {
			return data;
		}

		inline operator scalar* () {
			return data;
		}

		inline operator matrix () const {
			return matrix(d, 1, (const scalar*)this);
		}

		inline int dimension() const { return d; }
		inline int size() const { return d; }

		scalar squared() const;

		scalar length() const;

		vector& operator=(const vector& m);

	private:
		int d;
		float* data;
	};

	/*
	 * 
	 * Vector binary operators: Addition, subtraction, scaling,
	 */
	PLAPI vector operator +(const vector& v, const vector& u);
	PLAPI vector operator -(const vector& v, const vector& u);
	PLAPI vector operator *(const vector& v, const scalar a);
	inline vector operator *(const scalar a, const vector& v) { return v*a; }
	PLAPI scalar innerProduct(const vector& v, const vector& u);
	PLAPI matrix outerProduct(const vector& v, const vector& u);

	/*
	 * 3-component vector, [x y z]
	 */
	struct PLAPI vector3 : public vector {
	public:
		scalar& x;
		scalar& y;
		scalar& z;

		vector3(scalar* elements = nullptr):
			vector(3, elements), 
			x((*this)[0]), y((*this)[1]), z((*this)[2])
		{
			
		}

		vector3(scalar _x, scalar _y, scalar _z):
		vector3(nullptr) {
			this->x = _x;
			this->y = _y;
			this->z = _z;
		}
	};

	/*
	* 2-component vector, [x y z]
	*/
	struct PLAPI vector2 : public vector {
	public:
		scalar& x;
		scalar& y;

		vector2(scalar* elements = nullptr) :
			vector(2, elements),
			x((*this)[0]), y((*this)[1])
		{

		}

		vector2(scalar _x, scalar _y) :
			vector2(nullptr) {
			this->x = _x;
			this->y = _y;
		}
	};
}