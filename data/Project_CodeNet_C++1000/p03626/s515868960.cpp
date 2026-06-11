#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<string> s(2);
for(int i=0;i<2;i++)cin>>s[i];
ll ans=1;
int cnt=1;
bool ok=true;
for(int i=0;i<n-1;i++){
    if(s[0][i+1]==s[0][i]){cnt++;}
    else{
        if(ans==1){
            if(cnt==1){
                ans*=3;
                ok=false;
            }
            else {ans*=6;ok=true;}
        }
      else   if(cnt==1&&ok){
           ok=false;
        }
      else   if(cnt==2&&!ok){
            ans*=2;
            ok=true;
        }
        else if(cnt==1&&!ok)ans*=2;
        else if(cnt==2&&ok)ans*=3;
        cnt=1;
    }
    ans%=mod;
}
if(ans==1){
            if(cnt==1){
                ans*=3;
                ok=false;
            }
            else {ans*=6;ok=true;}
        }
 else if(cnt==2&&!ok){
            ans*=2;
  }
 else if(cnt==1&&!ok)ans*=2;
  else if(cnt==2&&ok)ans*=3;
    ans%=mod;
cout<<ans<<endl;
}