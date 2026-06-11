#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

bool dp1[35],dp2[3005];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    dp1[0]=1;
    for(int i=0;i<=30;i++){
        if(dp1[i]){
            if(i+a<=30) dp1[i+a]=1;
            if(i+b<=30) dp1[i+b]=1;
        }
    }
    dp2[0]=1;
    for(int i=0;i<=3000;i++){
        if(dp2[i]){
            if(i+c<=3000) dp2[i+c]=1;
            if(i+d<=3000) dp2[i+d]=1;
        }
    }
    int sug,wat;
    int x=0,y=1;
    for(int i=100;i<=f;i+=100){
        if(!dp1[i/100]) continue;
        for(int j=0;j<=f-i;j++){
            if(j>e*(i/100)) break;
            if(!dp2[j]) continue;
            if(x*(i+j)<=100*j*y){
                x=100*j;
                y=i+j;
                sug=j;
                wat=i;
            }
        }
    }
    cout<<sug+wat<<' '<<sug<<endl;
}
