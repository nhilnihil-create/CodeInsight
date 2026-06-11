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

int p[100000];
int main(){
  int N;
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> p[i];
  }

  int ans = 0;
  for(int i = 0; i < N - 1; i++){
    if(p[i] == i + 1){
      ans ++;
      p[i] = p[i + 1];
      p[i + 1] = i + 1;
    }
  }
  if(p[N - 1] == N){
    ans ++;
  }
  cout << ans << endl;
  return 0;
}
