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
#include <numeric>
#define IINF 1000000000
#define INF 9223372036854775807
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define EPS (1e-10)
#define REP(i, a, n) fo-r (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
//#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
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
#define bit(n,k) ((n>>k)&1)
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
ll cmp1(pair<ll,ll> a,pair<ll,ll> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se>b.se;
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
    //------------------------------
    ll n,W;cin>>n>>W;
    V<ll>w(n+1),v(n+1);
    for(ll i=1;i<=n;i++)cin>>w[i]>>v[i];

    V<Pll>wv;
    for(ll i=1;i<=n;i++){
        wv.pb(mp(w[i],v[i]));
    }
    sort(all(wv),cmp1);
    ll a0=0,a1=0,a2=0,a3=0;
    //map<ll,ll>M;
    ll a =wv[0].fi;
    for(ll i=0;i<n;i++){
        if(wv[i].fi==a){
            a0++;
        }
        else if(wv[i].fi==a+1){
            a1++;
        }
        else if(wv[i].fi==a+2){
            a2++;
        }
        else{
            a3++;
        }
    }
    ll s1=0,s2=0,s3=0,s4=0,abc2=0,abc3=0,abc4=0;
    for(ll i=0;i<n;i++){
        if(abc2==0){
            if(wv[i].fi==a+1){
                abc2=1;
                s2=i;
            }
        }
        if(abc3==0){
            if(wv[i].fi==a+2){
                abc3=1;
                s3=i;
            }
        }
        if(abc4==0){
            if(wv[i].fi==a+3){
                abc4=1;
                s4=i;
            }
        }
    }
    //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<Endl;
    ll ans=0;
    for(ll i=0;i<=a0;i++){
        ll sumw=0,res=0;
        for(ll x=s1;x<mmin(s1+i,n);x++){
            if(wv[x].fi==a){
               sumw+=wv[x].fi;
                res+=wv[x].se;
            }
        }
        ll sum1=sumw;
        ll res1=res;
        for(ll j=0;j<=a1;j++){
            sumw=sum1;
            res=res1;
            for(ll x=s2;x<mmin(s2+j,n);x++){
                if(wv[x].fi==a+1){
                   sumw+=wv[x].fi;
                    res+=wv[x].se;
                }
                else break;
            }
            ll sum2=sumw;
            ll res2=res;
            for(ll k=0;k<=a2;k++){
                sumw=sum2;
                res=res2;
                for(ll x=s3;x<mmin(s3+k,n);x++){
                    if(wv[x].fi==a+2){
                       sumw+=wv[x].fi;
                        res+=wv[x].se;
                    }
                    else break;
                }
                ll sum3=sumw;
                ll res3=res;
                for(ll q=0;q<=a3;q++){
                    sumw=sum3;
                    res=res3;
                    for(ll x=s4;x<mmin(s4+q,n);x++){
                        if(wv[x].fi==a+3){
                           sumw+=wv[x].fi;
                            res+=wv[x].se;
                        }
                        else break;
                    }
                    if(sumw>W)continue;
                    //cout<<sumw<<" "<<res<<endl;
                    chmax(ans,res);
                }
            }
        }
    }
    cout<<ans<<endl;
    //------------------------------
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //------------------------------- 
    return 0;
}
//----------------------------------------------------------------------



































