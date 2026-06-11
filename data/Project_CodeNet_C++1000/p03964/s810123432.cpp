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
#include <random>
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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin>>n;
    ll t[100010],a[100010];
    rep(i,n){
        cin>>t[i]>>a[i];
    }
    ll T=t[0],A=a[0];
    rep2(i,1,n){
        if(T<=t[i]&&A<=a[i]){
            T=t[i],A=a[i];
        }
        else{
            ll x[2],y[2];
            x[0]=(T/t[i]+(T%t[i]!=0))*t[i];
            y[0]=x[0]/t[i]*a[i];
            y[1]=(A/a[i]+(A%a[i]!=0))*a[i];
            x[1]=y[1]/a[i]*t[i];
            if(x[0]<T||y[0]<A){
                T=x[1],A=y[1];
            } else if(x[1]<T||y[1]<A){
                T=x[0],A=y[0];
            } else if(x[0]+y[0]<x[1]+y[1]){
                T=x[0],A=y[0];
            } else{
                T=x[1],A=y[1];
            }
        }
    }
    cout<<T+A<<endl;
    return 0;
}
