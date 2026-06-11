#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int nax = max({a, b, c});
    cout << (a + b + c - nax == nax ? "Yes" : "No") << endl;
}