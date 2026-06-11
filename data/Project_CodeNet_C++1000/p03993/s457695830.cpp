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
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        a[i]--;
    }
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        if(a[a[i]]==i)ans++;
    }
    cout <<ans/2 <<endl;
    return 0;
}

