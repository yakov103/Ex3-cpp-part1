#include "Matrix.hpp"
#include <vector>
namespace zich { 

    Matrix::Matrix (const vector<double> newData, const int newRow, const int newCol){
        if (newRow < 1 || newCol < 1 ){ 
            throw runtime_error("cols and rows must be possitve ");
        }
        this->data = newData; 
        this->rows = newRow ; 
        this->cols = newCol;

    }



        Matrix Matrix::operator+(const Matrix &b){
        
        if (this.cols != b.cols && this.rows != b.rows ){ 
            throw runtime_error ("size of Matrix must be the samw to sum them ! "); 
        }
        unsigned int size_of_matrix = this.rows * this.cols ; 
        vector <double> newMatrix ; 
        

        




        }
        Matrix &operator++();
        Matrix operator++(const int flag);
        Matrix &operator+=(const Matrix &b);
        Matrix operator-(const Matrix &b);
        Matrix &operator--();
        Matrix operator--(const int flag);
        Matrix &operator-=(const Matrix &b);
        Matrix operator*(const Matrix &b);
        Matrix operator*(const double a);
        Matrix &operator*=(const Matrix &b);
        Matrix &operator*=(const double a);
        bool operator>(const Matrix &b);
        bool operator<(const Matrix &b);
        bool operator!=(const Matrix &b);
        bool operator==(const Matrix &b);
        bool operator>=(const Matrix &b);
        bool operator<=(const Matrix &b);











}