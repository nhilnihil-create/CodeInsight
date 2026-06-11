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
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,p[100010],a[100010],b[100010];
    ll A,B;
    cin>>n;
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    a[p[0]]=1,b[p[0]]=1;
    rep2(i,1,n){
        a[p[i]]=20000*(p[i]-p[i-1])+a[p[i-1]];
        b[p[i]]=i+2-a[p[i]];
    }
    if(a[0]<=0){
        A=1-a[0];
        rep(i,n){
            a[i]+=A;
        }
    }
    if(b[n-1]<=0){
        B=1-b[n-1];
        rep(i,n){
            b[i]+=B;
        }
    }
    rep(i,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    rep(i,n){
        cout<<b[i]<<" ";
    }
    cout<<endl;/*
    rep(i,n){
        cout<<a[p[i]]+b[p[i]]<<" "; 
    }
    cout<<endl;*/
    return 0;
}