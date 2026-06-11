#include <bits/stdc++.h>
#define MAXN 200010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e18 + 7;


int main (){
    ios_base::sync_with_stdio(false);
    ll n, ta, aoki, a, t;

    cin >> n;
    cin >> ta >> aoki;

    for (int i=0; i<n-1; i++){
        cin >> t >> a;
        ll div = max((ta-1)/t + 1, (aoki - 1)/a + 1);
        ta = t*div;
        aoki = a*div;
    }

    cout << ta + aoki << endl;
    return 0;
}