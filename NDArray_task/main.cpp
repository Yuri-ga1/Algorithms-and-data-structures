﻿#include <iostream>
#include <limits.h>
#include <ctime>
#include <concepts>

using namespace std;

template <typename T>
concept Number = integral<T> || floating_point<T>;

template <typename T> class NDArray {
private:
	int rows, collums;
	int** p;

public:
	NDArray() {
		rows = 1;
		collums = 1;
		getZeros();
	}

	NDArray(int n) {
		rows = 1;
		collums = n;
		getZeros();
	}

	NDArray(int n, int m) {
		rows = n;
		collums = m;
		getZeros();
	}

	int getRows() {
		return rows;
	}

	int getCollums() {
		return collums;
	}

	int** getEmpty() {
		int** arr;
		arr = new int* [rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new int[collums];
		return arr;
	}

	int** getZeros() {
		p = getEmpty();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				p[i][j] = 0;
			}
		}
		return p;
	}

	int** getOnes() {
		p = getEmpty();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				p[i][j] = 1;
			}
		}
		return p;
	}

	int** getRand() {
		p = getEmpty();
		srand(time(NULL));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				p[i][j] = rand();
			}
		}
		return p;
	}

	NDArray operator+(const NDArray &m){
		if (rows != m.rows || collums != m.collums) {
			cout << "Incorrect matrix format";
			exit(1);
		}
		NDArray res(rows, collums);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				res.p[i][j] = p[i][j] + m.p[i][j];
			}
		}
		*this = res;
		return *this;
	}

	NDArray operator-(const NDArray& m) {
		if (rows != m.rows || collums != m.collums) {
			cout << "Incorrect matrix format";
			exit(1);
		}
		NDArray res(rows, collums);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				res.p[i][j] = p[i][j] - m.p[i][j];
			}
		}
		*this = res;
		return *this;
	}

	NDArray operator*(const NDArray& m) {
		if (rows != m.rows || collums != m.collums) {
			cout << "Incorrect matrix format";
			exit(1);
		}
		NDArray res(rows, collums);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				res.p[i][j] = p[i][j] * m.p[i][j];
			}
		}
		*this = res;
		return *this;
	}

	NDArray operator/(const NDArray& m) {
		if (rows != m.rows || collums != m.collums) {
			cout << "Incorrect matrix format";
			exit(1);
		}
		NDArray res(rows, collums);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < collums; j++) {
				res.p[i][j] = p[i][j] / m.p[i][j];
			}
		}
		*this = res;
		return *this;
	}


	//True matrix multiplication
	NDArray multi(NDArray matr1, NDArray matr2) {
		int collMatr1 = matr1.getCollums();
		int rowsMatr2 = matr2.getRows();

		if (collMatr1 != rowsMatr2) {
			cout << "Incorrect matrix format";
			exit(1);
		}
		cout << "collums = " << collMatr1 << "\nrows= " << rowsMatr2 << endl;
		NDArray res(rowsMatr2, collMatr1);

		for (int i = 0; i < collMatr1; i++) {
			for (int j = 0; j < rowsMatr2; j++) {
				res.p[i][j] = matr1.p[i][j] * matr2.p[j][i];
			}
		}
		return res;
	}

	NDArray transposition(NDArray matr) {
		int collMatr = matr.getCollums();
		int rowsMatr = matr.getRows();

		NDArray res(collMatr, rowsMatr);

		for (int i = 0; i < rowsMatr; i++) {
			for (int j = 0; j < collMatr; j++) {
				res.p[j][i] =  matr.p[i][j];
			}
		}
		return res;
	}

	NDArray median(NDArray matr, int code=3) {
		int sum = 0, counter = 0;
		if (code == 3) {
			NDArray res;
			for (int i = 0; i < matr.rows; i++) {
				for (int j = 0; j < matr.collums; j++) {
					sum += matr.p[i][j];
					counter++;
				}
			}
			res.p[0][0] = sum / counter;
			return res;
		}
		else if (code == 0) {
			NDArray res1(matr.collums);

			for (int i = 0; i < matr.collums; i++) {
				for (int j = 0; j < matr.rows; j++) {
					sum += matr.p[i][j];
					counter++;
				}
				res1.p[0][i] = float(sum / counter);
				sum = 0;
				counter = 0;
			}
			return res1;
		}
		else if (code == 1) {
			NDArray res2(matr.rows);

			for (int i = 0; i < matr.rows; i++) {
				for (int j = 0; j < matr.collums; j++) {
					sum += matr.p[i][j];
					counter++;
				}
				res2.p[0][i] = float(sum / counter);
				sum = 0;
				counter = 0;
			}
			return res2;
		}
		else {
			cout << "Incorrect code\n";
			exit(1);
		}
	}

	NDArray max(NDArray matr, int code = 3) {
		int sum = 0, maxVal = INT_MIN;
		if (code == 3) {
			NDArray res;
			for (int i = 0; i < matr.rows; i++) {
				for (int j = 0; j < matr.collums; j++) {
					sum += matr.p[i][j];
					if (matr.p[i][j] > maxVal)
						maxVal = matr.p[i][j];
				}
			}
			res.p[0][0] = sum / maxVal;
			return res;
		}
		else if (code == 0) {
			NDArray res1(matr.collums);

			for (int i = 0; i < matr.collums; i++) {
				for (int j = 0; j < matr.rows; j++) {
					sum += matr.p[i][j];
					if (matr.p[i][j] > maxVal)
						maxVal = matr.p[i][j];
				}
				res1.p[0][i] = sum / maxVal;
				sum = 0;
				maxVal = INT_MIN;
			}
			return res1;
		}
		else if (code == 1) {
			NDArray res2(matr.rows);

			for (int i = 0; i < matr.rows; i++) {
				for (int j = 0; j < matr.collums; j++) {
					sum += matr.p[i][j];
					if (matr.p[i][j] > maxVal)
						maxVal = matr.p[i][j];
				}
				res2.p[0][i] = sum / maxVal;
				sum = 0;
				maxVal = INT_MIN;
			}
			return res2;
		}
		else {
			cout << "Incorrect code\n";
			exit(1);
		}
	}

	NDArray min(NDArray matr, int code = 3) {
		int sum = 0, minVal = INT_MAX;
		if (code == 3) {
			NDArray res;
			for (int i = 0; i < matr.rows; i++) {
				for (int j = 0; j < matr.collums; j++) {
					sum += matr.p[i][j];
					if (matr.p[i][j] < minVal)
						minVal = matr.p[i][j];
				}
			}
			res.p[0][0] = sum / minVal;
			return res;
		}
		else if (code == 0) {
			NDArray res1(matr.collums);

			for (int i = 0; i < matr.collums; i++) {
				for (int j = 0; j < matr.rows; j++) {
					sum += matr.p[i][j];
					if (matr.p[i][j] > minVal)
						minVal = matr.p[i][j];
				}
				res1.p[0][i] = sum / minVal;
				sum = 0;
				minVal = INT_MAX;
			}
			return res1;
		}
		else if (code == 1) {
			NDArray res2(matr.rows);

			for (int i = 0; i < matr.rows; i++) {
				for (int j = 0; j < matr.collums; j++) {
					sum += matr.p[i][j];
					if (matr.p[i][j] > minVal)
						minVal = matr.p[i][j];
				}
				res2.p[0][i] = sum / minVal;
				sum = 0;
				minVal = INT_MAX;
			}
			return res2;
		}
		else {
			cout << "Incorrect code\n";
			exit(1);
		}
	}

	NDArray operator = (const NDArray& a)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < collums; j++)
				this->p[i][j] = a.p[i][j];
		return (*this);
	}

	friend ostream& operator<<(ostream& out,const NDArray& r) {
		for (int i = 0; i < r.rows; i++) {
			for (int j = 0; j < r.collums; j++) {
				out << r.p[i][j] << "\t";
			}
			out << endl;
		}
		return out;
	}

};

int main(){
	int x;
	cout << "ture";
	cin >> x;
}