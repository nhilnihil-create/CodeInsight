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
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 100000000
#define INF 300000000000000000
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define EPS (1e-10)
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp(pair<ll,Pll> a,pair<ll,Pll> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se.fi>b.se.fi;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_t=clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //-------------------------------
    ll n,m;cin>>n>>m;
    V<Pll>ab;
    V<ll>G[100010];
    for(ll i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        ab.pb({a,b});
    }
    sort(all(ab));
    map<Pll,ll>M;
    map<ll,ll>tri;
    for(ll i=0;i<m;i++){
        tri[ab[i].fi]++;
        tri[ab[i].se]++;
    }
    bool abc=1;
    /*for(auto it=M.begin();it!=M.end();it++){
        if(it->second%2!=0){
            abc=0;
            break;
        }
    }*/
    for(auto it =tri.begin();it!=tri.end();it++){
        if(it->second%2!=0){
            abc=0;
            break;
        }
    }
    //if(n%2!=m%2)abc=0;
    if(abc)cout<<"YES"<<endl;
    else cout<<"NO"<<Endl;
    //-------------------------------  
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------




















































