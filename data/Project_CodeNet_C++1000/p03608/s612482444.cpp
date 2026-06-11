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
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll dp[220][220];

int main(){cout<<fixed<<setprecision(10);
		   //ワーシャルフロイド法O(n^3)
           //順列全探索
           int n,m,r;
           cin>>n>>m>>r;
           vin city(r);
           rep(i,0,r){
             cin>>city[i];
            city[i]--; 
           }
           rep(i,0,220)rep(j,0,220){
             if(i!=j)dp[i][j]=INF;
           }
           ll a,b,c;
           rep(i,0,m){
             cin>>a>>b>>c;
             a--;b--;
             chmin(dp[a][b],c);
             chmin(dp[b][a],c);
           }
           rep(k,0,n){//途中点
            rep(j,0,n){
             rep(i,0,n){
              chmin(dp[i][j],dp[i][k]+dp[k][j]); 
             }
            }
           }
           
           ///////////////////
           vll order(r);
           rep(i,0,r) order[i]=i;
           ll ans=INF;
           do{
             ll cnt=0;
            rep(i,1,r){
              ll from=city[order[i-1]],to=city[order[i]];
             cnt+=dp[from][to];
            }
             chmin(ans,cnt);
           }while(next_permutation(order.begin(),order.end()));
           cout<<ans<<endl;
}


