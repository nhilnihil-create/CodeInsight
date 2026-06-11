#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int x, a, b; cin >> x >> a >> b;
    cout << (-a + b <= 0 ? "delicious" : -a + b > x ? "dangerous" : "safe") << endl;
}