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
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){cout<<fixed<<setprecision(20);
           //2文字と3文字を調べればok
		   string s;
           cin>>s;
           int n=s.size();
           rep(i,0,n-1){//2
             if(s[i]==s[i+1]){
              cout<<i+1<<" "<<i+2<<endl;
               return 0;
             }
           }
           rep(i,0,n-2){//3
             if(s[i]==s[i+2]){
              cout<<i+1<<" "<<i+3<<endl;
               return 0;
             }
           }
           cout<<-1<<" "<<-1<<endl;
}