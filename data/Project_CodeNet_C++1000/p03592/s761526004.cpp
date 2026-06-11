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
   int n,m,k;cin >>n>>m>>k;
   bool flg=false;
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=m; ++j) {
            int now=n*j+m*i-2*i*j;
            if(now==k)flg=true;
        }
    }
    if(flg)puts("Yes");
    else puts("No");
}
