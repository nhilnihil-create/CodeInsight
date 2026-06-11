#include <bits/stdc++.h>
#include <algorithm>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//最大公約数をユークリッドの互除法を使って求める
//計算量はlog(max(a,b))
//typedef long long ll;
ll gcd(ll a, ll b) {
    if(a % b == 0)
    return b;
    return gcd(b, a % b);
}


 
int main() {

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n)    cin >> a[i];

    sort(all(a));
    int g = a[0];
    rep(i,n-1) {
        g = gcd(g,a[i+1]);
    }
    if(k<=a[n-1] && k%g == 0)   cout<<"POSSIBLE"<<endl;
    else    cout<<"IMPOSSIBLE"<<endl;

 return 0;
}