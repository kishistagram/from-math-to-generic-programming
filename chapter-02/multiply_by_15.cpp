/*
15に対する最適な加算連鎖
同じ15aという計算でも、中間結果をうまく再利用することによって、加算回数を減らせる
*/

#include <iostream>


int multiply_by_15(int a)
{
	int b = (a + a) + a;
	int c = b + b;
	return (c + c) + b;
}

int main()
{
	int a = 10;
	std::cout << multiply_by_15(a) << std::endl;
}