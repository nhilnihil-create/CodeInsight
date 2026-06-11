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
    ll a,b,x;cin >>a>>b>>x;
    ll ans=a?b/x-(a-1)/x:b/x+1;
    cout <<ans <<endl;
    return 0;
}
