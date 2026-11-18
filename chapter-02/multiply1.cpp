/*
p.10 list 2-2
*/
#include <iostream>

bool odd(int n)
{
	return n & 0x1;
}
int half(int n)
{
	return (n >> 1);
}

int multiply1(int n, int a)
{
	std::cout << "CALL: n=" << n
              << " a=" << a << std::endl;

	if (n == 1)
		return (a);

	int result = multiply1(half(n), a + a);
	std::cout << result << std::endl;
	if (odd(n))
		result = result + a;

    std::cout << "RETURN: n=" << n
              << " result=" << result << std::endl;
	return (result);
}

int main()
{
	int nbai = 30;
	int value = 10;

	std::cout << multiply1(nbai, value) << std::endl;
}

/*

再帰: 
multiply1(30, 10)
    └── multiply1(15, 20)
            └── multiply1(7, 40)
                    └── multiply1(3, 80)
                            └── multiply1(1, 160)

掛け算は足し算だけで実装できる。そして同じ掛け算でも数学的な性質を利用すれば、
計算回数を大幅に減らせる
同じ数学的な関係を繰り返し適用できるから再帰を表現できる

数学的な性質を利用すると。。
30 * 10 = 15 * 20
		= 7 * 40 + 20
		= 3 * 80 + 40 + 20
		= 1 * 160 + 80 + 40 + 20
		= 300

単純な繰り返し計算がO(n)、
これはO(log n)

*/

/*
加算の合計数は以下のようになる

#+(n) = floor(log n) + (v(n) - 1)

floor(log n) -> 再帰の回数
(v(n) - 1) -> nの2進数表記における1の数＝ポップカウントと呼ばれる

例) nが１５の場合
2進数表記では
1 1 1 1
4回でてくる

実際にはn = 1の時処理されないから、4 - 1で3回加算されることが分かる



*/