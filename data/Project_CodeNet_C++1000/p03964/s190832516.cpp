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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<ll,ll>a,pair<ll,ll> b){
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
    //ll begin_time=clock();
    //-------------------------------
    ll n;cin>>n;
    ll ans=0;
    ll na=0,nt=0;
    for(ll i=0;i<n;i++){
        ll a,t;cin>>a>>t;
        if(i==0){
            ans=a+t;
            na=a;
            nt=t;
        }
        else{
            if(na%a!=0){
                for(ll j=1;;j++){
                    /*if(a*j>=na){
                        ans+=a*j-na;
                        na=a*j;
                        break;
                    }*/
                    ll tmp=na+j;
                    if(tmp%a==0){
                        ans+=j;
                        na+=j;
                        break;
                    }
                }
            }
            if(nt%t!=0){
                for(ll j=1;;j++){
                    /*if(t*j>=nt){
                        ans+=t*j-nt;
                        nt=t*j;
                        break;
                    }*/
                    ll tmp=nt+j;
                    if(tmp%t==0){
                        ans+=j;
                        nt+=j;
                        break;
                    }
                }
            }
            if(na/a*t<nt){
                ll new_na = nt/t*a;
                ans+=new_na-na;
                na=new_na;
            }
            else{
                ll new_nt = na/a*t;
                ans+=new_nt-nt;
                nt=new_nt;
            }
        }
    }
    cout<<ans<<Endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------



































