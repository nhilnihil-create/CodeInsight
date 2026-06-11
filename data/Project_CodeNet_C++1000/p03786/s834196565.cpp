#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    ll n;cin >>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        b[i]=a[i]*2;
    }
    sort(all(a));
    sort(all(b));
    vector<ll>sum(n+1,0);
    for (int i = 0; i < n; ++i) {
        sum[i+1]=sum[i]+b[i];
    }
    a.push_back(a[n-1]);
    ll ans=0;
    for (int i = 0; i < n + 1; ++i) {
        if(sum[i]<a[i])ans=i;
    }
    cout <<n-ans<<endl;
    return 0;
}

