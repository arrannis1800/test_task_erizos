#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>

int ParseInt1(std::string str)
{
	int res = 0;
	size_t size = str.size();
	int ascii_offset = 48;

	for(size_t i = 0; i < size; ++i)
	{
		res += (static_cast<int>(str[i])-ascii_offset) * pow(10,(size-i-1));
	}
	return res;
}

int ParseInt2(const char* str)
{
	int res = 0;
	int ascii_offset = 48;

	size_t i = 0;
	while(str[i] != '\0')
	{
		res *= 10;
		res += static_cast<int>(str[i])-ascii_offset;
		++i;
	}
	
	return res;
}

void SpiralPrint(std::vector<std::vector<int>>& matrix)
{
	if (matrix.size() == 0 or matrix[0].size() == 0) 
		return;

	size_t i = 0, j = 0, vir_zi=0,vir_zj=0;
	size_t col_size = matrix.size()-1;
	size_t row_size = matrix[0].size()-1;
	int dir = 0;
	for (size_t steps = 0; steps < (matrix.size() * matrix[0].size()); ++steps)
	{
		printf("%d ", matrix[j][i]);


		if (i == row_size and dir == 0)
		{
			++dir;
			++vir_zj;
		} else if (j == col_size and dir == 1)
		{
			++dir;
			--col_size;
		} else if (vir_zi == i and dir == 2)
		{
			++dir;
			--row_size;
		} else if(vir_zj == j and dir == 3)
		{
			dir = 0;
			++vir_zi;
		}
		 

		switch(dir)
		{
		case 0: ++i; break;
		case 1: ++j; break;
		case 2: --i; break;
		case 3: --j; break;
		}
	}
	printf("\n");

}


int main()
{
	// first task
	assert(ParseInt1("123") == 123);
	assert(ParseInt1("513") == 513);
	assert(ParseInt1("102003") == 102003);

	assert(ParseInt2("123") == 123);
	assert(ParseInt2("513") == 513);
	assert(ParseInt2("102003") == 102003);

	// second task 
	std::vector<std::vector<int>> matrix33 = {{1,2,3},{4,5,6},{7,8,9}};
	SpiralPrint(matrix33); // should be 1 2 3 6 9 8 7 4 5 

	std::vector<std::vector<int>> matrix43 = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	SpiralPrint(matrix43); // should be 1 2 3 6 9 12 11 10 7 4 5 8

	std::vector<std::vector<int>> matrix34 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	SpiralPrint(matrix34); // should be 1 2 3 4 8 12 11 10 9 5 6 7

	std::vector<std::vector<int>> matrix44 = {{1,2,3, 4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	SpiralPrint(matrix44); // should be 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
	
	getchar();  
	return 0;
}