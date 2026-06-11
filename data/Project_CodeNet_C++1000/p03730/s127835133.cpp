#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll a,b,c;
    cin >>a>>b>>c;
    bool flg=false;
    for (int i = 0; i < b; ++i) {
        if((a*i)%b==c)flg=true;
    }
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}

