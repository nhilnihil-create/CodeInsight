#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vp;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define MMOD(i) ((i%MOD)+MOD)%MOD;
#define all(v) v.begin() , v.end()
#define vec(i,j) vector<vector<ll>>(i,vector<ll>(j,0))
const ll INF=99999999999999;
const ll MOD=1000000007;
const ll MAX_N=100010;
ll a,b,c,d,e,f,x,y,z,k,m,n,l,h,w,t,ans=0;
vl v;
string s1,s2;
ll solve(void){
    a=1;
    rep(i,n){
        if(i==0||v[i]==a){
            ans+=(v[i]-1)/a;
            a++;
        }
        else{
            ans+=(v[i]-1)/a;
        }
    }
    return ans;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n){
        cin>>x;
        v.push_back(x);
    }
    cout<<solve()<<endl;
}