#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;

    long n = 1;
    long x = pow(10, 9) + 7;
    for (int i = 1; i <= N; i++)
    {
        n = n * (i % x);
        n = n % x;
    }

    cout << n << endl;

    return 0;
}