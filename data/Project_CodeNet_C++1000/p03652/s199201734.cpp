#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

queue <int> qs[300];
bool used[300];
int main(){
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        int A;
        cin >> A;
        qs[i].push(A);
      }
    }

    int ans = INT_MAX;
    for(int j = 0; j < M; j++){
      map <int, int> front_count;
      for(int i = 0; i < N; i++){
        auto tmp = qs[i].front();
        while(used[tmp - 1] && !qs[i].empty()){
          qs[i].pop();
          tmp = qs[i].front();
        }
        if(qs[i].empty()){
          break;
        }

        if(front_count.find(tmp) != front_count.end()){
          front_count[tmp] ++;
        } else {
          front_count[tmp] = 1;
        }
      }

      if(qs[0].empty()){
        break;
      }

      int max_count = 0;
      int max_count_sport = -1;
      for(auto it = front_count.begin(); it != front_count.end(); it++){
        if(max_count < it->second){
          max_count = it->second;
          max_count_sport = it->first;
        }
      }
      ans = min(ans, max_count);
      used[max_count_sport - 1] = true;
      front_count.erase(max_count_sport);
    }
    cout << ans << endl;
    return 0;
}