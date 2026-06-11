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
		   //dpdpdpdpdpdpdpdpdpdpdp
           //10^7 ok
           ll n,a;
           cin>>n>>a;
           vll x(n);
           rep(i,0,n)cin>>x[i];
           ll ans=0;
           rep(num,1,n+1){
            ll sum=a*num;
             ll dp[n+1][2525][n+1];//dp[i][j][k]=i枚目までで和がjになる通り数 (k枚選ぶ）
             rep(i,0,n+1){
              rep(j,0,2525){
                rep(k,0,n+1){
               dp[i][j][k]=0;
                if(i==0&&j==0&&k==0)dp[i][j][k]=1;
               //選ぶ
               if(i-1>=0&&j-x[i-1]>=0&&k-1>=0)dp[i][j][k]+=dp[i-1][j-x[i-1]][k-1];
               //選ばない
               if(i-1>=0)dp[i][j][k]+=dp[i-1][j][k];
               }
              }
             }
             ans+=dp[n][sum][num];
           }
          cout<<ans<<endl;
}