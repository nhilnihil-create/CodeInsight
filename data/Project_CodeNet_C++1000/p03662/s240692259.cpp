#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>

using namespace std;

vector <int> edges[100000];
bool fennecs[100000];
bool decided[100000];
bool used[100000];
int N;
int dfs(int cur, int depth){
  used[cur] = true;
  if(cur == N - 1){
    fennecs[N - 1] = false;
    decided[N - 1] = true;
    return depth;
  }
  int ret = -1;
  for(int i = 0; i < edges[cur].size(); i++){
    int next = edges[cur][i];
    if(used[next]){
      continue;
    }
    int tmp_ret = dfs(next, depth + 1);
    if(tmp_ret > 0){
      ret = tmp_ret;
      if(depth <= ret / 2){
        fennecs[cur] = true;
        decided[cur] = true;
      } else {
        fennecs[cur] = false;
        decided[cur] = true;
      }
    }
  }
  return ret;
}

void dfs_possession(int cur, int is_fennecs){
  decided[cur] = true;
  fennecs[cur] = is_fennecs;
  for(int i = 0;  i < edges[cur].size(); i++){
    int next = edges[cur][i];
    if(decided[next]){
      continue;
    }
    dfs_possession(next, is_fennecs);
  }
}

int main(){
  cin >> N;
  for(int i = 0; i < N - 1; i++){
    int a;
    int b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }

  int N_dist = dfs(0, 0);
  for(int i = 0; i < N; i++){
    if(decided[i]){
      dfs_possession(i, fennecs[i]);
    }
  }

  int fennecs_count = 0;
  for(int i = 0; i < N; i++){
    if(fennecs[i]){
      fennecs_count ++;
    }
  }


  if(fennecs_count > N - fennecs_count){
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
  return 0;
}
