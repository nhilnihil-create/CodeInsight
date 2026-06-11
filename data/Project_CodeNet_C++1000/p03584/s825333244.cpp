#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>
#include<fstream>
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
#include<unordered_set>
#include<random>
#include<functional>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
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
#define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,k,ans=0;
    ll a[100010],b[100010];
    cin>>n>>k;
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    // cout<<"------------"<<endl;
    rep(bit,31){
        ll sum=0;
        bool c=false;
        // if((1<<bit)>k) break;
        if((1<<bit)&k) c=true;
        ll s=k-(1<<bit);
        if(c)s=((s>>bit)<<(bit))|((1<<bit)-1);
        else s=k;
        // cout<<bit<<" "<<s<<endl;
        rep(i,n){
            // cout<<i<<" ";
            if((s|a[i])<=s){
                sum+=b[i];
                // cout<<1<<endl;
            }
            // else cout<<0<<endl;
            // bool ok=true;
            /*
            rep(j,31){
                if((1<<j)>a[i]) break;
                if(j>bit){
                    if(((1<<j)&a[i])&&!((1<<j)&k)){
                        ok=false;
                        break;
                    }
                }
                else if(bit==j){
                    if((1<<j)&a[i]){
                        ok=false;
                        break;
                    }
                }
                else{
                    if(c) continue;
                    else if(((1<<j)&a[i])&&!(1<<j)&k){
                        ok=false;
                        break;
                    }
                }
            }
            */
            // cout<<i<<" "<<ok<<endl;
            // if(ok) sum+=b[i];
        }
        // cout<<bit<<"#"<<sum<<endl;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}