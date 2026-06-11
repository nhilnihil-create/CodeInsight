//    https://youtu.be/N3oCS85HvpY

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
typedef pair<long long, long long> pll;
const long long inf = 2000000000000000000LL;	// 2e18
#define pi                  acos(-1.0)
#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define shesh               "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define bp                  pop_back
#define pf                  push_front
#define fp                  pop_front
#define ub                  upper_bound
#define lb                  lower_bound
#define all(x)              x.begin(), x.end()
#define debug(x)            cout<<"debug "<<x<<"\n"
#define mest(a,b)           memset(a,b,sizeof(a))

int main(){
    fast;
    ll t,n,m,i,j,k,temp,flag,ans=1,mod=1000000007;
    string s1,s2;
    cin>>n>>s1>>s2;
    vector<ll>v;
    for(i=0;i<n-1;i++){
        if(s1[i]==s1[i+1]){
            v.push_back(0);
            i++;
        }else{
           v.push_back(1);
        }
    }
    if(s1[n-1]==s2[n-1]) v.push_back(1);
    if(v[0]==1) ans*=3;
    else ans*=(3*2);
    for(i=1;i<v.size();i++){
        if(v[i]==0){
            if(v[i-1]==0){
                ans*=3;
                ans%=mod;
            }else{
                ans*=2;
                ans%=mod;
            }
        }else{
            if(v[i-1]==1){
                ans*=2;
                ans%=mod;
            }
        }
    }
    cout<<ans;
}
