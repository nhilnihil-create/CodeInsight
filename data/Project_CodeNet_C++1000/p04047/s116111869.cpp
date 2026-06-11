#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    int n;cin >>n;
    vector<int>l(2*n);
    for (int i = 0; i <2*n; ++i) {
        cin >>l[i];
    }
    sort(all(l));
    ll ans=0;
    for (int i = 0; i < 2*n; i+=2) {
        ans+=min(l[i],l[i+1]);
    }
    cout <<ans<<endl;
    return 0;
}

