#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 100100;
const long double PI = acos(-1);
 
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, t;
    cin >> n >> t;

    vector<ll> v(n);

    for (auto& x: v) cin >> x;

    ll carry = 0;
    for (int i=0; i<n-1; i++){
        v[i+1] -= carry;
        if (v[i+1] - v[i] > t){
            carry += v[i+1] - v[i] - t;
            v[i+1] = v[i]+ t;
        }
    }

    cout << v[n-1] + t << endl;
    return 0;
}