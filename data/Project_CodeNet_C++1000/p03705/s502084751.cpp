#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,a,b;cin>>n>>a>>b;
    if(n==1){
        if(a!=b)cout<<0<<endl;
        else cout<<1<<endl;
    }else{
        if(a>b)cout<<0<<endl;
        else cout<<(b-a)*(n-2)+1<<endl;
    }
    return 0;
}