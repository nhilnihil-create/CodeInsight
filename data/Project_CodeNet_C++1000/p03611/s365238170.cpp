#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
   int n;cin >>n;
   vector<int>a(n);
   map<int,int>cnt;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        cnt[a[i]]++;
        cnt[a[i]+1]++;
        cnt[a[i]-1]++;
    }
    int mx=0;
    for(auto p:cnt){
        mx=max(mx,p.second);
    }
    cout <<mx<<endl;
}
