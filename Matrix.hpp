#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
namespace zich {
    class Matrix {
    private:
        vector<double> data;
        int row;
        int col;


    public:

        double multiplicate_row_with_col(const Matrix &otherMat, const int row_to_mult, const int col_to_mult);

        double sum_of_matrix() const;

        Matrix(const vector<double> newData, const int newRow, const int newCol);

        Matrix operator+(const Matrix &otherMat);

        Matrix &operator++();

        Matrix operator++(const int flag);

        Matrix &operator+=(const Matrix &otherMat);

        Matrix operator-(const Matrix &otherMat);

        Matrix &operator--();

        Matrix operator--(const int flag);

        Matrix &operator-=(const Matrix &otherMat);

        Matrix operator*(const Matrix &otherMat);

        Matrix operator*(const double scaler);

        Matrix &operator*=(const Matrix &otherMat);

        Matrix &operator*=(const double scaler);

        bool operator>(const Matrix &otherMat);

        bool operator<(const Matrix &otherMat);

        bool operator==(const Matrix &otherMat);

        bool operator!=(const Matrix &otherMat);


        bool operator>=(const Matrix &otherMat);

        bool operator<=(const Matrix &otherMat);

        friend ostream &operator<<(ostream &os, const Matrix &scaler);

        friend Matrix operator*(const double scaler, Matrix &otherMat);

        friend Matrix operator-(Matrix &A);
    };

};