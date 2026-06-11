#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int f(long long A, long long B)
{
    int a = 1, b = 1;

    while (A >= 10)
    {
        a++;
        A = A / 10;
    }
    while (B >= 10)
    {
        b++;
        B = B / 10;
    }
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    long long N, x;
    int ans;
    int min = 11;
    

    cin >> N;

    for (long long i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            x = N / i;
            ans = f(x, i);
            if (ans < min)
                min = ans;
        }
    }

    cout << min << endl;

    return 0;
}