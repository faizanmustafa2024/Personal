#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//g++ -std=c++11 -Wall -Werror triMatMult.cpp -o matrix
// ./matrix 0A.txt 0B.txt
// ./matrix testA.txt testB.txt

// g++ -Wall -Werror -o ./tri_mat_mult.out triMatMult.cpp


std::vector<int> multiplyMatrices(const std::vector<int>& matrix1, const std::vector<int>& matrix2, int size1) {
    //std::vector<int> result(size1 * (size1 + 1) / 2, 0); //3 spaces with 0's in it
    std::vector<int> result;

    // Perform matrix multiplication

    for (int i = 0; i < size1; i++) {
        for (int j = i; j < size1; j++) {
           int sum = 0;
           for(int k = i; k <= j; k++){
            int indexA = i * (size1 -i)+(k + i - 1); 
            int indexB = k * (size1 - k) + (j + k - 1);

            if(i != 0 && indexA > 0 && indexB > 0){
                //if valid index, and i != 0
                sum += matrix1[indexA] * matrix2[indexB];
            }else {
                //original equation
                //sum += matrix1[i * (size1 -i)+(k - i)] * matrix2[k * (size1 - k) + (j -k)];
                sum += matrix1[i * (size1 -i)+(k - i)] * matrix2[k * (size1 - k) + (j -k)];
            }     
           }
           result.push_back(sum);

        }
    }

    return result;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << "<file_path1> <file_path2>" << std::endl;
        return 1;
    }

    const char* file1 = argv[1];
    const char* file2 = argv[2];

    //read contents of first file
    std::ifstream inFile1(file1);
    int size1;
    inFile1 >> size1;

    std::vector<int> matrix1; //create a vector matrix1
    int value1;
    while (inFile1 >> value1) {
        matrix1.push_back(value1);
    }
    inFile1.close();

    //read contents of second file
    std::ifstream inFile2(file2);
    int size2;
    inFile2 >> size2;

    std::vector<int> matrix2; //create a vector matrix2
    int value2;
    while (inFile2 >> value2) {
        matrix2.push_back(value2);
    }
    inFile2.close();

     //print matrix 1 contents
    /*std::cout << "Matrix1 contents:" << std::endl;
    for (int i = 0; i < matrix1.size(); ++i) {
        std::cout << matrix1[i] << " ";
    }
    std::cout << std::endl;

    //print matrix 2 contents
    std::cout << "Matrix2 contents:" << std::endl;
    for (int i = 0; i < matrix2.size(); ++i) {
        std::cout << matrix2[i] << " ";
    }
    std::cout << std::endl;

    std:: cout << "size1 = " << size1 << " & size 2 = " << size2 << std::endl;*/

    // Multiply matrix1 by matrix2
    std::vector<int> result = multiplyMatrices(matrix1, matrix2, size1);

    // Print the result
    for (int i = 0; i < size1 * (size1 + 1)/2; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0; 
}