#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;


int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    cout << (a.back() == b.front() && b.back() == c.front() ? "YES" : "NO") << endl;
}