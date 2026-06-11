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


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,m,a[500][500];
    cin>>n>>m;
    rep(i,n)rep(j,m){
        cin>>a[i][j];
    }
    ll ans=n;
    bool used[400]={};
    rep(i,m){
        map<ll,ll> mp;
        ll cnt=0;
        rep(j,n){
            rep(k,m){
                if(used[a[j][k]]==0){
                    mp[a[j][k]]++;
                    break;
                }
            }
        }
        rep2(j,1,m+1){
            cnt=max(cnt,mp[j]);
        }
        rep2(j,1,m+1){
            if(mp[j]==cnt&&used[j]==0){
                used[j]=1;
                break;
            }
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}