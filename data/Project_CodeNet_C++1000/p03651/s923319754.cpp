#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 1<<30
#define MOD 1000000007
#define mod 10007
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    ll n,k;cin>>n>>k;
    V<ll>a(n);
    bool abc=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k)abc=1;
    }
    if(abc==1){
        cout<<"POSSIBLE"<<endl;
        return 0;
    }
    sort(all(a));
    if(a[n-1]<k){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    ll minc=INF;
    for(ll i=1;i<n;i++){
        if(a[i]==a[i-1])continue;
        chmin(minc,a[i]-a[i-1]);
    }
    if(minc==1){
        cout<<"POSSIBLE"<<endl;
        return 0;
    }
    else{
        for(ll i=0;i<n;i++){
            if(a[i]>k){
                if((a[i]-k)%minc==0){
                    cout<<"POSSIBLE"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------































