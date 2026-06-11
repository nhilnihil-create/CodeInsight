#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b)
        cout << "YES";
    else
        cout << "NO";
}