#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const int MAXN=1;
const ll MOD=1;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
ll factor[MAXN];
void cal_factor(){factor[0]=1;for(int u=1;u<MAXN;u++){factor[u]=(factor[u-1]*u)%MOD;}}
ll C(ll n,ll k){return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;}
int N;
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    int c0=0,c1=0,c2=0;
    for(int u=0;u<N;u++){
        int cnt=0;
        int a;
        cin>>a;
        while(a%2==0){
            a/=2;
            cnt++;
        }
        if(cnt==0)c0++;
        else if(cnt==1)c1++;
        else c2++;
    }
    if(c1==0){
        if(c0-c2<=1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    else {
        if(c0<=c2)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}