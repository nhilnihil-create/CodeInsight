#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
普通にとっていけばいいんじゃないかこれ
なんか工夫いるかな
とっては確認とか
先にたんてんきめちゃうとか
1 234とか
12 13つなぐと1がたんてんでなくなる
1個スタートきめて限界まで
1固定でもいいかな
ああ
1-2-7-8
-3
-4-5-6
とか困るのか
いや
1-3でいいのか

*/
vector<vector<ll>> G;
deque<ll> Q;

vector<bool> seen;
void dfs1(ll v) {
  Q.push_back(v);
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs1(next_v);
    break;
  }
}

void dfs2(ll v) {
  Q.push_front(v);
  seen[v] = true;
  for (auto next_v : G[v]) { 
    if (seen[next_v]) continue;
    dfs2(next_v);
    break;
  }
}

int main() {
  ll N,M; cin>>N>>M;
  G.assign(N+1,vector<ll>(0,0));
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  seen.assign(N+1, false);
  dfs1(1);
  seen[1]=false;
  Q.pop_front();//1とる
  dfs2(1);
  ll qsz=Q.size();
  cout<<qsz<<endl;
  while(!Q.empty()){
    cout<<Q.front()<<" ";
    Q.pop_front();
  }
  cout<<endl;
}