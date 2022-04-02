#include "Matrix.hpp"

namespace zich {

    Matrix::Matrix( vector<double> const newData, const int newRow, const int newCol) {
        if (newRow <= 0 || newCol <= 0) {
            throw runtime_error("The size must be positive");
        }

        this->data = newData;
        row = newRow;
        col = newCol;
    }

    Matrix Matrix::operator+(const Matrix &otherMat) {
        if (this->row != otherMat.row || this->col != otherMat.col) {
            throw runtime_error("The matrices should be the same size");
        }

        unsigned int length = (unsigned int)(row * col);
        vector<double> newData;
        newData.resize(length);
        for (unsigned int i = 0; i < length; i++) {
            newData[i] = this->data[i] + otherMat.data[i];

        }
        return Matrix(newData, row, col);
    }

    Matrix &Matrix::operator++() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[(unsigned int)(i * col + j)] += 1;
            }
        }
        return *this;
    }

    Matrix Matrix::operator++(const int flag) {
        Matrix copy = *this;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[(unsigned int)(i * col + j)] += 1;
            }
        }
        return copy;
    }

    Matrix &Matrix::operator+=(const Matrix &otherMat) {
        if (this->row != otherMat.row || this->col != otherMat.col) {
            throw runtime_error("The matrices should be the same size");
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[(unsigned int)(i * col + j)] += otherMat.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &otherMat) {
        if (this->row != otherMat.row || this->col != otherMat.col) {
            throw runtime_error("The matrices should be the same size");
        }
        unsigned int length = (unsigned int)(row * col);
        vector<double> newData;
        newData.resize(length);
        for (unsigned int i = 0; i < length; i++) {
            newData[i] = this->data[i] - otherMat.data[i];

        }
        return Matrix(newData, row, col);
    }

    Matrix &Matrix::operator--() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[(unsigned int)(i * col + j)] -= 1;
            }
        }
        return *this;
    }

    Matrix Matrix::operator--(const int flag) {
        Matrix copy = *this;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[(unsigned int)(i * col + j)] -= 1;
            }
        }
        return copy;
    }

    Matrix &Matrix::operator-=(const Matrix &otherMat) {
        if (this->row != otherMat.row || this->col != otherMat.col) {
            throw runtime_error("The matrices should be the same size");
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[(unsigned int)(i * col + j)] -= otherMat.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }

    double Matrix::multiplicate_row_with_col(const Matrix &otherMat, const int row_to_mult, const int col_to_mult) {
        double sum = 0;
        for (int i = 0; i < this->col; i++) {
            sum += this->data[(unsigned int)(this->col * row_to_mult + i)] * otherMat.data[(unsigned int)(otherMat.col * i + col_to_mult)];
        }
        return sum;
    }

    Matrix Matrix::operator*(const Matrix &otherMat) {
        if (this->col != otherMat.row) {
            throw runtime_error("The sizes of the matrices do not match");
        }
        vector<double> n;
        Matrix newMatrix(n, row, otherMat.col);
        for (int i = 0; i < newMatrix.row; i++) {
            for (int j = 0; j < newMatrix.col; j++) {
                newMatrix.data[(unsigned int)(i * newMatrix.col + j)] = multiplicate_row_with_col(otherMat, i, j);
            }
        }
        return newMatrix;
    }

    Matrix Matrix::operator*(const double scaler) {
        Matrix newMatrix = *this;
        for (unsigned int i = 0; i < row; i++) {
            for (unsigned int j = 0; j < col; j++) {
                newMatrix.data[(unsigned int)(col) * i + j] *= scaler;
            }
        }
        return newMatrix;
    }

    Matrix &Matrix::operator*=(const Matrix &otherMat) {
        *this = (*this * otherMat);
        return *this;
    }

    Matrix &Matrix::operator*=(const double scaler) {
        *this = (*this * scaler);
        return *this;
    }

    double Matrix::sum_of_matrix() const {
        double sum = 0;
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                sum += data[(unsigned int)(i * (this->col) + j)];
            }
        }
        return sum;
    }

    bool Matrix::operator>(const Matrix &otherMat) {
        return (*this).sum_of_matrix() > otherMat.sum_of_matrix();
    }

    bool Matrix::operator<(const Matrix &otherMat) {
        return (*this).sum_of_matrix() < otherMat.sum_of_matrix();
    }

    bool Matrix::operator==(const Matrix &otherMat) {

        if (this->row != otherMat.row || this->col != otherMat.col) {
            return false;
        }
        unsigned int size = (unsigned int)(row * col);
        for (unsigned int i = 0; i < size; i++) {
            if (this->data[i] != otherMat.data[i]) {
                return false;
            }
        }
        return true;

    }

    bool Matrix::operator!=(const Matrix &otherMat) {
        return !(((*this) == otherMat));
    }


    bool Matrix::operator>=(const Matrix &otherMat) {
        return ((*this) > otherMat) || ((*this) == otherMat);
    }

    bool Matrix::operator<=(const Matrix &otherMat) {
        return ((*this) < otherMat) || ((*this) == otherMat);
    }

    ostream &operator<<(ostream &COUT, const Matrix &scaler) {
        for (int i = 0; i < scaler.row; i++) {
            COUT << "|";
            for (int j = 0; j < scaler.col; j++) {
                COUT << scaler.data[(unsigned int)(scaler.col * i + j)] << " ";
            }
            COUT << "|" << endl;
        }
        return COUT;
    }
    
    Matrix operator*(const double scaler, Matrix &otherMat) {
        return otherMat * scaler;
    }

    Matrix operator-(Matrix &A) {
        return A *= -1;
    }
}