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

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    V<int> a(26,0);
    rep(i,h) rep(j,w){
        char c;
        cin>>c;
        a[c-'a']++;
    }
    bool ok=1;
    if((h*w)%2==0){
        rep(i,26) if(a[i]%2==1) ok=0;
    }else{
        int cnt=0;
        rep(i,26) if(a[i]%2==1) cnt++;
        if(cnt!=1) ok=0;
        if(ok){
            rep(i,26){
                if(a[i]%2==1) a[i]--;
            }
        }
    }
    if(ok){
        int c4=0,c2=0;
        rep(i,26){
            if(a[i]>0){
                if(a[i]%4==0) c4++;
                else if(a[i]%2==0) c2++;
            }
        }
        int ma=0;
        if(h%2==1) ma+=w/2;
        if(w%2==1) ma+=h/2;
        if(c2>ma) ok=0;
        else if((ma-c2)%2==1) ok=0;
    }
    YN(ok);
}