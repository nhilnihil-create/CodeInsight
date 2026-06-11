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
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    ll bigf=0;
    ll smaf=0;
    for(ll i=1;i<n;i++){
        if(v[i-1]<v[i]){
            if(smaf==1){
                smaf=0;
                sum++;
                //bigf=1;
            }else{
                bigf=1;
            }
        }else if(v[i-1]>v[i]){
            if(bigf==1){
                bigf=0;
                sum++;
                //smaf=1;
            }else{
                smaf=1;
            }
        }
    }
    sum++;
    cout<<sum<<endl;
    return 0;
}
