//bit全探索
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

bool red[110000];
int cnt[110000];

int main(){cout<<fixed<<setprecision(10);
		   int n,m;
           cin>>n>>m;
           int x,y;
           red[1]=1;
           rep(i,0,n)cnt[i+1]=1;
           rep(i,0,m){
             cin>>x>>y;
             if(red[x])red[y]=1;
             cnt[x]--;
             cnt[y]++;
             if(cnt[x]==0)red[x]=0;
           }
           int ans=0;
           rep(i,0,n)if(red[i+1]&&cnt[i+1]>0)ans++;
           cout<<ans<<endl;
}