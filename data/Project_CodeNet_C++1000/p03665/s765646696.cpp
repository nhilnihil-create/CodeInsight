// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    ll p;
    cin>>n>>p;
    vector<ll> v(n);
    rep(i,n) {
        cin>>a;
        if(a%2) f=1;
    }

    if(!f){
        if(p){
            cout<<0<<endl;
        }else {
            sum=1;
            rep(i,n) sum*=2;
            cout<<sum<<endl;
        }
    }else{
                    sum=1;
            rep(i,n-1) sum*=2;
            cout<<sum<<endl;
    }
    return 0;
}
