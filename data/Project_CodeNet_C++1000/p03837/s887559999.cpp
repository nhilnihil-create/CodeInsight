#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;


int main(){
    int n,m;cin >>n>>m;
    V a(m);
    V b(m);
    V c(m);
    VVl d(n,Vl(n,INF));
    for (int i = 0; i < n; ++i) {
        d[i][i]=0;
    }
    for (int i = 0; i < m; ++i) {
        cin >>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
        d[a[i]][b[i]]=c[i];
        d[b[i]][a[i]]=c[i];
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    ll ans=0;
    for (int i = 0; i < m; ++i) {
        if(d[a[i]][b[i]]!=c[i])ans++;
    }
    cout <<ans <<endl;
}