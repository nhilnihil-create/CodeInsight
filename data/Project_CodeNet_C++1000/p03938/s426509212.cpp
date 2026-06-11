#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> p(n);
    for(i = 0;i < n;++i){
        cin >> p.at(i);
    }
    vector<ll> r(n);
    for(i = 0;i < n;++i){
        r.at(p.at(i)-1) = i + 1;
    }
    vector<ll> a(n);
    vector<ll> b(n);
    for(i = 0;i < n;++i){
        a.at(i) = (n+1)*(i+1);
        b.at(i) = (n+1)*(n-i-1) + r.at(i);
    }

    for(i = 0;i < n-1;++i){
        cout << a.at(i) << " ";
    }
    cout << a.at(i) << endl;
    for(i = 0;i < n-1;++i){
        cout << b.at(i) << " ";
    }
    cout << b.at(i) << endl;

    return 0;
}