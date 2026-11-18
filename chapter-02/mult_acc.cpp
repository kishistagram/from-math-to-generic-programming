#include <iostream>

bool odd(int n)
{
	return n & 0x1;
}
int half(int n)
{
	return (n >> 1);
}

int mult_acc(int r, int n, int a)
{
	if (n == 1)
		return r + a;
	if (odd(n))
	{
		return mult_acc(r + a, half(n), a + a);
	}
	else
	{
		return mult_acc(r, half(n), a + a);
	}

}

int main()
{

}