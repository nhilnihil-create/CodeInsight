#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main()
{
    ll i,j;
    string a;
    cin >> a;
    ll n = a.size();
    vector<ll> z(128, 0);
    for(i = 0;i < n;++i){
        ++z.at(a.at(i));
    }
    ll ans = 0;
    for(i = 0;i < 128;++i){
        ans += z.at(i)*(z.at(i)-1)/2;
    }
    cout << n*(n-1)/2 - ans + 1 << endl;
    return 0;
}