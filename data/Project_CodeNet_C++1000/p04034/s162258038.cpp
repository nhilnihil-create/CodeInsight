#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true; // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G[v]) {
      if (seen[next_v]) continue; // next_v が探索済だったらスルー
      dfs(G, next_v); // 再帰的に探索
  }
}

int main()
{
    int N,M;
    cin >> N >> M;
    vint red(N,0);
    vint cnt(N,1);
    red[0] = 1;
    REP(i,M){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]--;
        cnt[b]++;
        if(red[a] == 1)red[b] = 1;
        if(cnt[a] == 0)red[a]--;
    }
    int ans = 0;
    REP(i,N){
        if(cnt[i] != 0 && red[i] == 1)ans++;
    }
    cout << ans << endl;

}