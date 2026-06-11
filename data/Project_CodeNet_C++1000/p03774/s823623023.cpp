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

int main(){cout<<fixed<<setprecision(20);
           int n,m;
           cin>>n>>m;
           vin a(n),b(n);
           vin c(m),d(m);
           rep(i,0,n)cin>>a[i]>>b[i];
           rep(i,0,m)cin>>c[i]>>d[i];
           rep(i,0,n){
            int ans=0;
             int cnt=inf;
             rep(j,0,m){
               if(chmin(cnt,abs(a[i]-c[j])+abs(b[i]-d[j]))){
                 ans=j+1;
               }
             }
                     cout<<ans<<endl;
           }
}