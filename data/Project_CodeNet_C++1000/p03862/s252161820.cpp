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
		   ll n,x;
           cin>>n>>x;
           vll a(n);
           rep(i,0,n)cin>>a[i];
           ll sum=0;
           //後ろを食べれば良い？
           rep(i,0,n-1){
             if(a[i]+a[i+1]>x){
               ll q=a[i]+a[i+1];
               sum+=q-x;
               //-に注意
               if(a[i+1]>=q-x)a[i+1]-=q-x;
               else {
                 a[i+1]=0;
               }
             }
           }
           cout<<sum<<endl;
}