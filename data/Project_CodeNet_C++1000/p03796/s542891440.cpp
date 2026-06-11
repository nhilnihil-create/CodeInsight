#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   int n;cin >>n;
   ll ans=1;
    for (int i = 0; i < n; ++i) {
        ans*=(i+1);
        ans%=mod;
    }
    cout <<ans <<endl;
}
