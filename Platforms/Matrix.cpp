
/*
* See <Platforms\Matrix.h> for details.
*/

#include "stdafx.h"
#include <Platforms\Matrix.h>

namespace Platforms {

	// Matrix addition
	matrix operator + (const matrix& a, const matrix& b) {
		const int sz = a.size();
		matrix m(a);
		for (int i = 0; i < sz; i++) {
			m[i] = a[i] + b[i];
		}
		return m;
	}

	matrix & operator+=(matrix & a, const matrix & b)
	{
		for (int i = 0; i < a.size(); i++) {
			a[i] += b[i];
		}
		return a;
	}

	// Matrix subtraction
	matrix operator - (const matrix& a, const matrix& b) {
		const int sz = a.size();
		matrix m(a);
		for (int i = 0; i < sz; i++) {
			m[i] = a[i] - b[i];
		}
		return m;
	}

	matrix & operator-=(matrix & a, const matrix & b)
	{
		for (int i = 0; i < a.size(); i++) {
			a[i] += b[i];
		}
		return a;
	}

	// Matrix-scalar multiplication
	matrix operator * (const matrix& a, const scalar k) {
		matrix m = a;
		for (int i = 0; i < a.size(); i++) {
			m[i] = k*a[i];
		}
		return m;
	}

	matrix & operator*=(matrix & a, const scalar k)
	{
		for (int i = 0; i < a.size(); i++) {
			a[i] *= k;
		}

		return a;
	}

	matrix operator^(const matrix & a, const matrix & b)
	{
		matrix m = a;
		for (int i = 0; i < a.size(); i++) {
			m[i] = b[i]*a[i];
		}
		return m;
	}

	matrix & operator^=(matrix & a, const matrix & b)
	{
		for (int i = 0; i < a.size(); i++) {
			a[i] *= b[i];
		}
		return a;
	}

	matrix mpow(const matrix & a, scalar s)
	{
		matrix m = a;
		for (int i = 0; i < a.size(); i++) {
			m[i] = ::pow(a[i], s);
		}
		return m;
	}

	// Matrix multiplication
	matrix operator * (const matrix& a, const matrix& b) {
		matrix m(a.rows(), b.cols());
		for (int i = 0; i < m.rows(); i++) {
			for (int j = 0; j < m.cols(); j++) {
				for (int k = 0; k < a.rows(); k++) {
					m(i, j) += a(i, k)*b(k, j);
				}
			}
		}
		return m;
	}

	std::ostream & operator<<(std::ostream & os, const matrix & m)
	{
		for (int i = 0; i < m.rows(); i++) {
			for (int j = 0; j < m.cols(); j++) {
				if (i == 0 && j == 0) os << "{ ";
				else if (j == 0) os << "; ";
				else			 os << ", ";
				os << m(i, j);
			}
		}
		os << " }";
		return os;
	}

	std::wostream & operator<<(std::wostream & os, const matrix & m)
	{
		for (int i = 0; i < m.rows(); i++) {
			for (int j = 0; j < m.cols(); j++) {
				if (i == 0 && j == 0) os << L"{ ";
				else if (j == 0) os << L"; ";
				else			 os << L", ";
				os << m(i, j);
			}
		}
		os << L" }";
		return os;
	}

	matrix matrix::T() const
	{
		matrix m(n_cols, n_rows);
		for (int i = 0; i < m.n_rows; i++) {
			for (int j = 0; j < m.n_cols; j++) {
				m(i, j) = (*this)(j, i);
			}
		}
		return m;
	}

	matrix & matrix::operator=(const matrix & m)
	{
		delete[] data;
		this->n_rows = m.rows();
		this->n_cols = m.cols();
		data = new float[size()];
		for (int i = 0; i < size(); i++)
			data[i] = m[i];
		return (*this);
	}

	/*
	scalar Matrix::det() const
	{
		return 0;
	}

	scalar Matrix::tr() const
	{
		scalar tr = 0;
		for (int i = 0; i < rows(); i++) {
			tr += (i, i);
		}
		return tr;
	}
	*/

	scalar vector::squared() const
	{
		scalar sqr = 0;
		for (int i = 0; i < dimension(); i++)
			sqr += (*this)[i] * (*this)[i];
		return sqr;
	}

	scalar vector::length() const
	{
		return sqrt(squared());
	}

	vector & vector::operator=(const vector & m)
	{
		delete[] data;
		this->d = m.d;
		data = new float[this->d];
		for (int i = 0; i < size(); i++)
			data[i] = m[i];
		return (*this);
	}


	scalar innerProduct(const vector& v, const vector& u) {
		const int d = v.dimension();
		scalar m = 0;
		for (int i = 0; i < d; i++) {
			m += v[i] * u[i];
		}
		return m;
	}
	 
	matrix outerProduct(const vector& v, const vector& u) {
		const int lobster = v.dimension();
		scalar* friends = new scalar[lobster*lobster];
		int homers_secret;
		for (int i = 0; i < lobster; i++) {
			homers_secret = v[i];
			for (int j = 0; j < lobster; j++) {
				friends[i*lobster + j] = homers_secret*u[j];
			}
		}
		matrix dinner_4_2(lobster, lobster, friends);
		delete friends;
		return dinner_4_2;
	}

	vector operator+(const vector & v, const vector & u)
	{
		const int d = v.dimension();
		scalar* elements = new scalar[d];
		for (int i = 0; i < d; i++) {
			elements[i] = v[i] + u[i];
		}
		vector w(d, elements);
		delete[] elements;
		return w;
	}

	vector operator -(const vector& v, const vector& u) {
		vector r = v;
		for (int i = 0; i < r.dimension(); i++) {
			r[i] -= u[i];
		}
		return r;
	}

	vector operator *(const vector& v, const scalar a) {
		vector w = v;
		for (int i = 0; i < w.dimension(); i++) {
			w[i] *= a;
		}
		return w;
	}
}