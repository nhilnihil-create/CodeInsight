#include <bits/stdc++.h>
using namespace std;
using edge= pair<int, int64_t>;
using Graph= vector<vector<edge>>;
const int64_t INF= 1e15;

void solve(const Graph &gph, int s, vector<int64_t> *scores){
  const int N= gph.size();

  scores->at(s)= 0;
  queue<int> s_inf;
  for(int d=1; d<=N; d++){
    for(int from=0; from<N; from++){
      for(auto e:gph.at(from)){
        int to; int64_t reward;
        tie(to, reward)= e;
        if(scores->at(to) < scores->at(from)+ reward){
          scores->at(to)= scores->at(from)+ reward;

          if(d==N){
            scores->at(to)= INF;
            s_inf.push(to);
          }
        }
      }
    }
  }

  if(s_inf.size()){
    while( !s_inf.empty() ){
      int from= s_inf.front();
      s_inf.pop();
      for(auto e:gph.at(from)){
        int to;
        tie(to, ignore)= e;

        if(scores->at(to) < INF){
          scores->at(to)= INF;
          s_inf.push(to);
        }
      }
    }
  }
}

int main(){
  int N,M;
  cin >> N >> M;

  Graph gph(N);
  int v1,v2; int64_t score;
  for(int j=0; j<M; j++){
    cin >> v1 >> v2 >> score;
    v1--; v2--; // 1-indexed -> 0-indexed
    gph.at(v1).emplace_back(make_pair(v2, score));
  }

  vector<int64_t> scores(N, -INF);
  solve(gph, 0, &scores);

  string ans= (scores.back() < INF) ? to_string(scores.back())
                                    : "inf";

  cout << ans << endl;
}