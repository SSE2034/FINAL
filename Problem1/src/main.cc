#include<iostream>
#include<stdlib.h>
#include "MATLAB.h"
int main(int argc, char **argv){
    using namespace std;
    int mat1_rownum = atoi(argv[1]);
    int mat1_colnum = atoi(argv[2]);

#ifdef matrix_matrix
    int mat2_rownum = atoi(argv[3]);
    int mat2_colnum = atoi(argv[4]);
    // 1.2 constructor test
    Matrix matrix1(mat1_rownum,mat1_colnum);
    Matrix matrix2(mat2_rownum,mat2_colnum);

    // 1.3 mutator function test
    for(int i=0;i<mat1_rownum;i++){
        for(int j=0;j<mat1_colnum;j++){
            matrix1.set_value(i,j,atoi(argv[i*mat1_colnum+j+5]));
        }
    }

    for(int i=0;i<mat2_rownum;i++){
        for(int j=0;j<mat2_colnum;j++){
            matrix2.set_value(i,j,atoi(argv[i*mat2_colnum+j+5+mat1_rownum*mat1_colnum]));
        }
    }
    cout << "=====matrix1=====" << endl;
    matrix1.print_matrix();
    cout << "=====matrix2=====" << endl;
    matrix2.print_matrix();


    //===== NOTICE =======//
    //test can be performed in an integer or float type to test template// 
    //The test below will contain followings.
    //1.2 copy constructor / destructor test
    //1.3 accessor function test
    //1.4 matrix printing function test
    //1.5 operator overloading test
    //1.6 template test

    /****** + operator test ******/
    // plus operation with 2 matrix
    // when matrix size is equal
#if mm_mode
    Matrix result(mat1_rownum,mat1_colnum);
    result = matrix1 + matrix2;
    cout << "=====result_add=====" << endl;
    result.print_matrix();

    /****** - operator test ******/
    // minus operation with 2 matrix
    // matrix size is equal

    result = matrix1 - matrix2;
    cout << "=====result_sub=====" << endl;
    result.print_matrix();
#else 
    /****** * operator test ******/
    // multiply operation with 2 matrix
    // when mat1's rownum is equal to mat2's colnum 
    
    Matrix result(mat1_rownum,mat2_colnum);
    result = matrix1 * matrix2;
    cout << "=====result_mul=====" << endl;
    result.print_matrix();
#endif

#endif

#ifdef matrix_value
    // 1.2 constructor test
    Matrix matrix1(mat1_rownum,mat1_colnum);
    float value;
    // 1.3 accessor function test
    for(int i=0;i<mat1_rownum;i++){
        for(int j=0;j<mat1_colnum;j++){
            matrix1.set_value(i,j,atoi(argv[i*mat1_colnum+j+3]));
        }
    }

    value = atoi(argv[3+mat1_rownum*mat1_colnum]);

    cout << "=====matrix1=====" << endl;
    matrix1.print_matrix();
    cout << "======value======" << endl;
    cout << value << endl;
    
    //===== NOTICE =======//
    //test can be performed in an integer or float type to test template// 

    /****** + operator test2 ******/
    // plus operation with 1 matrix and integer
    // integer is added from each element
    Matrix result(mat1_rownum,mat1_colnum);
    result = matrix1 + value;
    cout << "=====result_add=====" << endl;
    result.print_matrix();

    /****** - operator test2 ******/
    // minus operation with 1 matrix and integer
    // integer is subtracted from each element

    result = matrix1 - value;
    cout << "=====result_sub=====" << endl;
    result.print_matrix();

    /****** * operator test2 ******/
    // minus operation with 1 matrix and integer
    // integer is multiplied from each element

    result = matrix1 * value;
    cout << "=====result_mul=====" << endl;
    result.print_matrix();

#endif
}
    
