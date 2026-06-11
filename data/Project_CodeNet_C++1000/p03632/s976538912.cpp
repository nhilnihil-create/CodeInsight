#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

 // 深さ優先探索
vector<bool> seen;
int dfs(const Graph &G, ll v) {
    seen[v] = true; // v を訪問済にする
    int score = 0; 

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー

        // 負荷さ優先探索中の処理



        dfs(G, next_v); // 再帰的に探索, 毎回mat渡してええの？
    }
    return score;
} 

/*
//桁数の計算
ll keta(ll num){
  ll ans= 0 ;
  ll rem;

  for (ll i = 4; i >= 0 ; i--){
    rem = pow(10,i);
    ans += (num / rem); 
    num = num % rem;
  }
  return ans;
}
*/


int main() {
    ll A, B , C, D;
    cin >> A >> B >> C >> D;
    //vector<vector<char>> s(H, vector<char>(W));


    if (B <= C || D <= A) cout << 0 << endl;
    else if (A <= C && D <= B) cout << D-C << endl;
    else if (C <= A && B <= D) cout << B-A << endl;
    else if (C <= A && D <= B) cout << D-A << endl;
    else if (A <= C && B <= D) cout << B-C << endl;


    return 0;
}