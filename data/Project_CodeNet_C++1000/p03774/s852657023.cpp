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

ll d(P a,P b){
    return abs((a.first-b.first))+abs((a.second-b.second));
}

int main() {
   int n,m;cin >>n>>m;
   vector<Pll>stu(n);
   vector<Pll>pos(m);
    for (int i = 0; i < n; ++i) {
        ll a,b;cin >>a>>b;
        stu[i]={a,b};
    }
    for (int j = 0; j < m; ++j) {
        ll c,d;cin >>c>>d;
        pos[j]={c,d};
    }
    vector<int>ans(n);
    for (int i = 0; i < n; ++i) {
        ll mint=INFll;
        for (int j = 0; j < m; ++j) {
            if(d(stu[i],pos[j])<mint){
                ans[i]=j;
                mint=d(stu[i],pos[j]);
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        cout <<ans[k]+1<<endl;
    }
}