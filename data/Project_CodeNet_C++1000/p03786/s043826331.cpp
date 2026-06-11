#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    ll n; cin >> n;
    ll sum = 0,ans =  0;
    vector<ll> a(n);

    rep(i,n) cin >> a[i];

    sort(a.begin(),a.end());

    sum = a[0];

    for(int i = 1; i < n; i ++){
        if(sum*2 < a[i]){
            ans = i;
        }
        sum += a[i];
    }

    if(n == 2) cout << ((a[0]*2 >= a[1])?2:1);
    else cout << n-ans;
}