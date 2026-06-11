// lcmとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
using namespace std;


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>a>>b>>c>>d>>n;
    a*=4;
    b*=2;
    mini=min(a,b);
    mini=min(mini,c);
    if(mini*2>d&&n!=1){
        sum=n/2*d;
        if(n%2) sum+=mini;
    }else{
        sum=n*mini;
    }
    cout<<sum<<endl;
    return 0;
}
