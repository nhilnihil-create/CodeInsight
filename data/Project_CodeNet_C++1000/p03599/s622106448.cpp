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
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    int ans1=0,ans2=0;
    double maxdensity=-1.0;
    for(int x=0;x*a*100<=f;x++){
        for(int y=0;y*b*100<=f;y++){
            for(int p=0;p*c<=30*e;p++){
                for(int q=0;q*d<=30*e;q++){
                    if(x*100*a+y*100*b+p*c+q*d<=f){
                        if(p*c+q*d<=(x*a+y*b)*e){
                            double density = (double)100.0*(p*c+q*d)/(x*100*a+y*100*b+p*c+q*d);
                            if(maxdensity<=density){
                                maxdensity=density;
                                ans1=(x*100*a+y*100*b+p*c+q*d);
                                ans2=(p*c+q*d);
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<ans1<<" "<<ans2<<endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------






































