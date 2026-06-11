#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll nax = 1e10;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        nax = min((ll)(a + b), nax);
    }
    cout << nax << endl;
}