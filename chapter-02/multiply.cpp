#include <iostream>
/*
加算回数 #+(n) = n - 1
時間計算量 O(n)

再帰によってnを1ずつ減らす方法
*/

int multiply0(int n, int a, int &addCount)
{
    std::cout << "[CALL] n=" << n
              << ", a=" << a << std::endl;

    if (n == 1)
        return a;

    int result = multiply0(n - 1, a, addCount);

    ++addCount;
    result = result + a;

    std::cout << "[RETURN] n=" << n
              << ", result=" << result
              << ", additions=" << addCount
              << std::endl;

    return result;
}

int main()
{
    int count = 0;

    int result = multiply0(5, 10, count);

    std::cout << "Result: " << result << std::endl;
    std::cout << "Total additions: " << count << std::endl;
}