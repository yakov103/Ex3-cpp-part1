#include "Matrix.hpp"
using namespace std;
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
        newMatrix.resize(size_of_matrix);
        for (int i = 0 ; i < size_of_matrix ; i++){
            newMatrix[i]= this->data[i] + b.data[i];
        }

        return Matrix(newMatrix, this->rows, this->cols);
        }



        Matrix &operator++(){
            unsigned int size_of_matrix = this.rows * this.cols ;
            for (int i = 0 ; i < size_of_matrix ; i++){
                this->data[i]+= 1;
            }
        return *this;
        }


        Matrix operator++(const int flag);


        Matrix &operator+=(const Matrix &b){
            return *this + b ;
        }


        Matrix operator-(const Matrix &b);
    {
    if (this.cols != b.cols && this.rows != b.rows ){
    throw runtime_error ("size of Matrix must be the same to sum them ! ");
    }
    unsigned int size_of_matrix = this.rows * this.cols ;
    vector <double> newMatrix ;
    newMatrix.resize(size_of_matrix);
    for (int i = 0 ; i < size_of_matrix ; i++){
    newMatrix[i]= this->data[i] - b.data[i];
    }

    return Matrix(newMatrix,this->rows , this->cols);


    }
        Matrix &operator--(){
            unsigned int size_of_matrix = this.rows * this.cols ;
            for (int i = 0 ; i < size_of_matrix ; i++){
                this->data[i]+= 1;
            }
            return *this;
        }
        Matrix operator--(const int flag);

        Matrix &operator-=(const Matrix &b){
            return *this - b;
        }

double multiplication (const Matrix &b , const int row , const int col ){
    double resualt = 0 ;
    for ( unsigned int i = 0 ; i < this->cols ; i ++ ){
        resualt += this->data[(unsigned int)(this->col * row + i)] * b.data[(unsigned int)(b.cols * i + col)];
    }
    return resualt;



}


Matrix operator*(const Matrix &b){
          if ( this->cols != b.rows ){
              throw runtime_error("this matrix cannot be multiplciated ! ");
          }
          vector <double> newMatrix ;
          unsigned int newsize = this->rows*b.cols ;
          newMatrix.resize(newsize );
            for (unsigned int i = 0; i < this->rows; i++)
            {
                for (unsigned int j = 0; j < b.cols; j++)
                {
                    newMatrix[unsigned int (i*(b.cols)+j) ] = multiplication(b, i, j);
                }
            }

            return Matrix(newMatrix,this->rows, b.cols);
        }
        Matrix operator*(const double a){
        Matrix mat = *this;

        for (unsigned int i = 0 ; i < mat.cols * mat.rows ; i ++){
            mat.Data[i] *=a ;
        }
        return mat;

        }
        Matrix &operator*=(const Matrix &b){
            *this = (*this * b );
            return *this;
        }

        Matrix &operator*=(const double a){
            *this = (*this * a);
            return *this ;
        }
     double Matrix::sumOfMat (){
           double resualt = 0;
           for ( unsigned int i =0 ; i < this->cols*this->rows ;i++){
               resualt += this->data[i];

           }
            return resualt;
        }

        bool operator>(const Matrix &b){
            return
        }
        bool operator<(const Matrix &b);
        bool operator!=(const Matrix &b);
        bool operator==(const Matrix &b);
        bool operator>=(const Matrix &b);
        bool operator<=(const Matrix &b);











}