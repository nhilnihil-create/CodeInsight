#include <bits/stdc++.h>
using namespace std;
using Graph= vector<vector<int64_t>>;
const int64_t NINF= -1e15;

string solve(const Graph &weights){
  const int N= weights.size();
  Graph dp= weights;
  for(int k=0; k<N; k++){
    for(int from=0; from<N; from++){
      for(int to=0; to<N; to++){
        if(dp.at(from).at(k) != NINF && dp.at(k).at(to) != NINF){
          dp.at(from).at(to)= max(dp.at(from).at(to), dp.at(from).at(k)+dp.at(k).at(to));
        }
      }
    }
  }

  bool is_inf= false;
  for(int v=0; v<N; v++){
    if(dp.at(0).at(v) != NINF && dp.at(v).at(v) > 0 && dp.at(v).back() != NINF){
      is_inf= true;
      break;
    }
  }

  string ans= is_inf ? "inf"
                     : to_string(dp.at(0).back());
  return ans;
}

int main(){
  int N,M;
  cin >> N >> M;

  Graph rewards(N, vector<int64_t>(N, NINF));
  for(int v=0; v<N; v++){
    rewards.at(v).at(v)= 0;
  }
  int v1,v2,score;
  for(int j=0; j<M; j++){
    cin >> v1 >> v2 >> score;
    v1--; v2--; // 1-indexed -> 0-indexed
    rewards.at(v1).at(v2)= score;
  }

  cout << solve(rewards) << endl;
}