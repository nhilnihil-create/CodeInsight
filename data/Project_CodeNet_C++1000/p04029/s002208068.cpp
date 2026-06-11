#include<bits/stdc++.h>
using namespace std;
inline void io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
}
int main()
{
    io();
    int n;
    cin >> n;
    cout << (n * n + n) / 2 << '\n';
    return 0;
}