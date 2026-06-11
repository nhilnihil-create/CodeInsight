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
    string s;cin >>s;
    ll n=s.size();
    bool flg=false;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='9')flg=true;
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}