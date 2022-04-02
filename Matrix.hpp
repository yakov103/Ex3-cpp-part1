
#include <iostream>
#include <vector> 
#include <stdexcept> 


using namepsace std; 


namespace zich {
    class Matrix { 
       // private : 
        public :
        vector <double > data; 
        int rows ; 
        int cols ;

        double multiplication (Matrix & a , Matrix & b );
        double sumOfMat ();

        Matrix (const vector<double> newData, const int newRow, const int newCol); 
        Matrix operator+(const Matrix &b);
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

        friend ostream &operator<<(ostream & COUT, const Matrix &a);
        friend Matrix operator*(const double a, Matrix &b);
        friend Matrix operator-(Matrix &a);



    }











}