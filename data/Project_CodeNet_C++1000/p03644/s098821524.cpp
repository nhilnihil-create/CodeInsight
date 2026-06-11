// https://atcoder.jp/contests/abc068/tasks/abc068_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 1;
    while ((x << 1) <= n)
    {
        x <<= 1;
    }
    cout << x << endl;
    return 0;
}