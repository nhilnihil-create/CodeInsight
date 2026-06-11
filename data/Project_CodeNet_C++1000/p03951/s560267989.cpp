// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
//#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,n,maxi=0,f=0,mini=INF;
    ll sum=0;
    string str,sub;
    ll h,w;
    ll m,k;
    cin>>n;
    cin>>str>>sub;
    string d,e;
    ll ans=n*2;
    for(ll i=1;i<=n;i++){
        d=sub.substr(0,i);
        e=str.substr(str.length()-i,i);
        if(d==e) maxi=max(maxi,i);
    }
    cout<<ans-maxi<<endl;
    return 0;
}
