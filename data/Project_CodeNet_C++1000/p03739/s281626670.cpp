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
#define mt make_tuple
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
typedef unsigned long long int ull;
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
    //ll begin_time=clock();
    //-------------------------------
    ll n;cin>>n;
    V<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    bool abc=0;
    ll ans1=0,ans2=0;
    bool yn=0;

    yn=1;
    if(a[0]<=0)ans1+=1-a[0];
    ll sum=mmax(a[0],1);
    for(ll i=1;i<n;i++){
        if(yn==1){
            if(sum+a[i]<0){
                sum+=a[i];
            }
            else{
                ans1+=sum+a[i]+1;
                sum=-1;
            }
        }
        else{
            if(sum+a[i]>0){
                sum+=a[i];
            }
            else{
                ans1+=1-(sum+a[i]);
                sum=1;
            }
        }
        yn=1-yn;
    }
        yn=0;
        if(a[0]>=0)ans2+=a[0]+1;
        sum=mmin(-1,a[0]);
        for(ll i=1;i<n;i++){
            if(yn==1){
                if(sum+a[i]<0){
                    sum+=a[i];
                }
                else{
                    ans2+=sum+a[i]+1;
                    sum=-1;
                }
            }
            else{ 
                if(sum+a[i]>0){
                    sum+=a[i];
                }
                else{
                    ans2+=1-(sum+a[i]);
                    sum=1;
                }
            }
            yn=1-yn;
        }


    cout<<mmin(ans1,ans2)<<Endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------



























