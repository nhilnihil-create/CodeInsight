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
    ll n;cin >>n;
    string s;cin >>s;
    ll ans=0;
    ll now=0;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='I')now++;
        else now--;
        ans=max(ans,now);
    }
    cout <<ans <<endl;
    return 0;
}