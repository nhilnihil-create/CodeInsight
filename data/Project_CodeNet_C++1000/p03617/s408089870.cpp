#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    ll q,h,s,d;
    cin >> q >> h >> s >> d;
    ll n;
    cin >> n;
    vector<ll> a = {8*q, 4*h, 2*s, d};
    sort(a.begin(),a.end());
    vector<ll> b = {4*q, 2*h, s};
    sort(b.begin(),b.end());
    cout << (n/2)*a[0] + (n%2)*b[0] << endl;
} 