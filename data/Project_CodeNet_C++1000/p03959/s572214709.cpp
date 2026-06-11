#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

vector<pair<ll,ll>> range;


int main(){cout<<fixed<<setprecision(10);
		   ll n;
           cin>>n;
           vll t(n),a(n);
           rep(i,0,n)cin>>t[i];
           rep(i,0,n)cin>>a[i];
           range.resize(n);
           ll mn=0,mx=0;
           rep(i,0,n){
             if(t[i]>mx){
              mx=t[i];
              mn=t[i];
             }
             else{
              mn=1; 
             }
             range[i]=mp(mn,mx);
           }
           //a
           mn=0;mx=0;
           rep(i,0,n){
             mn=1;
             
             if(a[n-1-i]>mx){
               mx=a[n-1-i];
               mn=mx;
             }
             ll p,q;
             p=range[n-1-i].first;
             q=range[n-1-i].second;
             if(q<mn||mx<p){
              cout<<0<<endl;
               return 0;
             }
             mn=max(mn,p);
             range[n-1-i]=mp(mn,min(mx,q));
           }
           ll ans=1;
           rep(i,0,n){
            ans*=range[i].second-range[i].first+1;
             ans%=inf;
           }
           cout<<ans<<endl;
}