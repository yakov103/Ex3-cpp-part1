#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace zich;

TEST_CASE("good inputs ")
{
    // identity check
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    Matrix mat2(identity, 3, 3);
    CHECK((mat == mat2));

    //minus check
    std::vector<double> emptyMat = {0,0,0,0,0,0,0,0,0};
    Matrix eptyMat3on3(emptyMat,3,3);
    mat2 = mat2-mat;
    CHECK((eptyMat3on3 == mat2));

    // multiplicater by scaler
    std::vector<double> test1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix test12(test1,3,3);
    mat = mat*3;
    CHECK((mat) == test12);

    std::vector<double> mattoMult1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matToMult1(mattoMult1, 3, 3);
    matToMult1 = matToMult1 * int(2);
    std::vector<double> resAfterMult = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix restafterMultt2(resAfterMult, 3, 3);
    CHECK((matToMult1 == restafterMultt2));

    // check * operator double
    std::vector<double> matDouble = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat3(matDouble, 3, 3);
    mat3 = mat3 * double(2.5);
    std::vector<double> values_to_mat2 = {2.5, 0, 0, 0, 2.5, 0, 0, 0, 2.5};
    Matrix mat4(values_to_mat2, 3, 3);
    CHECK((mat3 == mat4));

    // check ++ operator
    mat++;
    std::vector<double> test3 = {4, 1, 1, 1, 4, 1, 1, 1, 4};
    Matrix test31(test3, 3, 3);
    CHECK((mat == test31));



    //check multiplication
//    std::vector<double> toMult1 = {3,5,7,3,2,3};
//    Matrix toMultMat1(toMult1,3,2);
//    std::vector<double> toMult2 = {-5,3,3,1,3,2};
//    Matrix toMultMat2(toMult2,2,3);
//    std::vector<double> resultMuly = {-10,24,19,-32,30,27,-7,15,12};
//    Matrix restMalt(resultMuly,3,3);
//    CHECK ((toMult1 == restMalt));


}
TEST_CASE("Bad inputs"){
    std::vector <double> testMatrix= {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector <double> testMatrix2= {1,1,1,1};
    std::vector <double> emptyVecoter= {};

    CHECK_THROWS(Matrix(testMatrix,-3,3));//try minus size
    CHECK_THROWS(Matrix(testMatrix,3,-3));//try minus size
    CHECK_THROWS(Matrix(testMatrix,-3,-3));//try minus size
    CHECK_THROWS(Matrix(testMatrix,2,3));// bad size input
    CHECK_THROWS(Matrix(testMatrix,3,2));// bad size input
    CHECK_THROWS(Matrix(testMatrix,2,2));// bad size input

    CHECK_THROWS(Matrix(emptyVecoter,0,0));// you cannot init empty vector
    CHECK_THROWS(Matrix(emptyVecoter,2,0));// you cannot init empty vector
    CHECK_THROWS(Matrix(emptyVecoter,2,2));// you cannot init empty vector


    Matrix mat(testMatrix,3,3);
    Matrix mat2(testMatrix2,2,2);
    CHECK_THROWS(mat*mat2);// bad size multiplication
    CHECK_THROWS(mat2*mat);// bad size multiplication


}
