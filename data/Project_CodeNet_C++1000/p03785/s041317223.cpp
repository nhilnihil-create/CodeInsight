#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){cout<<fixed<<setprecision(10);
          int n,c,k;
           cin>>n>>c>>k;
           vin t(n);
           rep(i,0,n)cin>>t[i];
           sort(all(t));
           int limit;
           int ans=0;
           int cnt=0;
           rep(i,0,n){
             limit=t[i]+k;
             cnt=0;
             cnt++;
             while(i+1<n&&t[i+1]<=limit&&cnt<c){
              i++;
              cnt++;
             }
             //cout<<cnt;
             //cout<<i<<endl;
             ans++;
           }
            
           cout<<ans<<endl;
          }