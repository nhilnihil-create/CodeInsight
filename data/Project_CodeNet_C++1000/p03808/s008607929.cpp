#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    ll Z = n*(n+1)/2LL;

    if(sum%Z != 0) {
        cout << "NO" << endl;
        return 0; 
    }

    ll k = sum/Z;    

    vector<ll> d(n);
    rep(i, n-1) {
        d[i] = a[i+1] - a[i];
    }
    d[n-1] = a[0] - a[n-1];

    rep(i, n) {
        if(d[i] - k > 0 || (d[i] - k)%n != 0) {
            cout << "NO" << endl;
            return 0; 
        }
    }

    cout << "YES" << endl;
    return 0;
}