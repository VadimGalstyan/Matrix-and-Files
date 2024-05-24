#include "matrix.h"
#include <fstream>

int stringToInteger(const std::string& str)
{
    int value = 0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        value = value * 10 + (str[i] - '0');
    }
    
    return value;
}

int main()
{
    std::ofstream fout;
    fout.open("matrix1.txt");

    Matrix matrix1(4,4);
    matrix1.matrixInit();
    matrix1.print();

    if (fout.is_open())
    {
        int rows = matrix1.getRow();
        int cols = matrix1.getColumn();

        for(int i =0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                fout << matrix1[i][j] << std::endl;;
            }
        }
        fout.close();
    }
    
    Matrix matrix2(4,4);
    matrix2.matrixInit();
    matrix2.print();

    fout.open("matrix2.txt");
    
    if (fout.is_open())
    {
        int rows = matrix2.getRow();
        int cols = matrix2.getColumn();

        for(int i =0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                fout << matrix2[i][j] << std::endl;
            }
        }

        fout.close();
    }

    std::fstream fin1;
    std::fstream fin2;

    fin1.open("matrix1.txt");
    fin2.open("matrix2.txt");

    fout.open("sum.txt");

    if (matrix1.getRow() == matrix2.getRow() && matrix1.getColumn() == matrix2.getColumn())
    {
        int rows = matrix2.getRow();
        int cols = matrix2.getColumn();

        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                std::string str1;
                std::string str2;

                getline(fin1,str1);
                getline(fin2,str2);

                int x = stringToInteger(str1) + stringToInteger(str2);
                fout << x << " ";
            }
            fout << std::endl;
        } 
    }
    
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}
