#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, k; cin >> n >> k;
    int G = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        G = __gcd(a[i], G);
    }

    bool res = false;
    for(int i = 0; i < n; i++) {
        if(a[i] - k >= 0 && (a[i] - k) % G == 0)res = true;
    }
    cout << (res ? "POSSIBLE" : "IMPOSSIBLE" ) << endl;

}