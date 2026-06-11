#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
    ll n,t[100010],a[100010],ans=1;
    ll ha[100010],ht[100010];
    bool htt[100010]={},haa[100010]={};
    cin>>n;
    rep(i,n){
        cin>>t[i];
    }
    rep(i,n){
        cin>>a[i];
    }
    ht[0]=t[0];htt[0]=1;
    ha[n-1]=a[n-1];haa[n-1]=1;
    rep2(i,1,n){
        if(t[i]>t[i-1]){
            ht[i]=t[i];
            htt[i]=1;
        }
        else{
            ht[i]=t[i];
        }
    }
    for(ll i=n-2;i>=0;i--){
        if(a[i]>a[i+1]){
            ha[i]=a[i];
            haa[i]=1;
        }
        else{
            ha[i]=a[i];
        }
    }
    rep(i,n){
        // printf("%lld,ht:%lld,htt:%d,ha:%lld,haa:%d\n",i,ht[i],htt[i],ha[i],haa[i]);
        if(haa[i]&&htt[i]&&ht[i]!=ha[i]){
            ans*=0;
        }
        else if(haa[i]&&!htt[i]){
            if(ht[i]<ha[i]) ans*=0;
        }
        else if(!haa[i]&&htt[i]){
            if(ht[i]>ha[i]) ans*=0;
        }
        else if(!haa[i]&&!htt[i]){
            ans*=min(ht[i],ha[i]);
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
