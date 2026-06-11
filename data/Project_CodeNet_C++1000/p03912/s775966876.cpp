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
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const int INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;

bool compare(pll a, pll b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,m;
    pll x[100010];
    ll cnt[100010];
    ll cntm[200010];
    cin>>n>>m;
    rep(i,n){
        ll X;
        cin>>X;
        x[i]=pll(X%m,X);
        cntm[X%m]++;
    }
    sort(x,x+n,compare);
    ll now=1;
    rep(i,n-1){
        if(x[i].sc==x[i+1].sc) now++;
        else {
            cnt[x[i].fi]+=now/2;
            now=1;
        }
    }
    if(now!=1) cnt[x[n-1].fi]+=now/2;
    ll ans=0;
    rep(i,m/2+1){
        if(i==0||(m%2==0&&i==m/2)){
            ans+=cntm[i]/2;
        }
        else {
            ll a=cntm[i],A=cnt[i];
            ll b=cntm[m-i],B=cnt[m-i];
            ll s=min(a,b),t=max(a,b);
            if(a-b<=1&&a-b>=0){
                ans+=s;
            }
            else if(a-b>1){
                ans+=s;
                if((a-s)/2<=A){
                    ans+=(a-s)/2;
                }
                else{
                    ans+=A;
                }
            }
            else if(b-a<=1){
                ans+=s;
            }
            else if(b-a>1){
                ans+=s;
                if((b-s)/2<=B){
                    ans+=(b-s)/2;
                }
                else{
                    ans+=B;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}