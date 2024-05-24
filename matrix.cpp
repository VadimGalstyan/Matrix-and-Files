#include "matrix.h"

Matrix::Matrix(int row,int col) : rows(row),cols(col)
	{
		ptr = new int*[rows];
		for(int i = 0;i < rows;++i)
		{
			ptr[i] = new int[cols];
		}
	}

Matrix::Matrix(const Matrix& obj)
	{
		rows = obj.rows;
		cols = obj.cols;

                ptr = new int*[rows];
                for(int i = 0;i < rows;++i)
                {
                        ptr[i] = new int[cols];
                }

	        for(int i =0;i < rows;++i)
		{
			for(int j = 0;j < cols;++j)
			{
				ptr[i][j] = obj.ptr[i][j];
			}
		}
	}

Matrix& Matrix::operator=(const Matrix& obj)
	{
		if(this != &obj)
		{
			if(rows != obj.rows || cols != obj.cols)
			{
				for(int i = 0;i < rows;++i)
                                {  
                                 delete [] ptr[i];
                                }
                                delete[] ptr;
			}
                        
		rows = obj.rows;
                cols = obj.cols;

                ptr = new int*[rows];
                for(int i = 0;i < rows;++i)
                {
                        ptr[i] = new int[cols];
                }

                for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
                                ptr[i][j] = obj.ptr[i][j];
                        }
                }
		}

		return *this;
	}

Matrix::Matrix(Matrix&& obj) : rows(obj.rows),cols(obj.cols),ptr(obj.ptr)
	{
		std::cout<<"Move ctor"<<std::endl;
		obj.ptr = nullptr;
		obj.cols = 0;
		obj.rows = 0;

	}

Matrix& Matrix::operator=(Matrix&& obj)
	{
		std::cout <<"Assignment move " << __FUNCTION__ << std::endl;

		if(this != &obj)
		{
        for(int i = 0;i < rows;++i)
		{
			delete [] ptr[i];
		}
		    delete[] ptr;

		        rows = obj.rows;
                cols = obj.cols;
				ptr = obj.ptr;

				obj.ptr = nullptr;
		        obj.cols = 0;
		        obj.rows = 0;

		}

		return *this;
	}

Matrix::~Matrix()
	{
		for(int i = 0;i < rows;++i)
		{
			delete [] ptr[i];
			ptr[i] = nullptr;
		}
		delete[] ptr;
		ptr = nullptr;
	}

Matrix& Matrix::operator++()
	{
                for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
                                ptr[i][j] += 3;
                        }
                }
		return *this;
	}

Matrix Matrix::operator++(int)
	{
		Matrix tmp = *this;
		++(*this);
		return tmp;
	}

Matrix::RowProxy Matrix::operator[](const int& index) const
{
    return RowProxy(ptr[index]);
}

void Matrix::printSize()const
	{
		std::cout<<"Rows: "<<rows<<std::endl;
		std::cout<<"Cols: "<<cols<<std::endl;

	}

void Matrix::print() const
	{
		for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
				std::cout<<ptr[i][j]<<" ";
                        }
			std::cout<<std::endl;
                }
		std::cout<<std::endl;
	}

void Matrix::matrixInit()
	{
        srand(time(NULL));
		for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
                                ptr[i][j] = rand() % 10;
                        }
                }
	}

int Matrix::getRow() const
{
    return rows;
}
 
int Matrix::getColumn() const
{
    return cols;
}


//RowProxy
Matrix::RowProxy::RowProxy(int* const r) : row(r) {}

int& Matrix::RowProxy::operator[](const int& index) {
    return row[index];
}
