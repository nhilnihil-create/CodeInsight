#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>a(3*n);
    for (int i = 0; i < 3*n; ++i) {
        cin >>a[i];
    }
    sort(all(a));
    ll ans=0;
    ll tmp=3*n;
    for (int i = 0; i < n; ++i) {
        ans+=a[tmp-2];
        tmp-=2;
    }
    cout <<ans <<endl;
    return 0;
}

