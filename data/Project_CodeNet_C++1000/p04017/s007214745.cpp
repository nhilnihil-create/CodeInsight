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
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
long long x[100000];
int next_hotel[30][100000];
int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x[i];
  }
  long long L;
  cin >> L;

  for(int i = 0; i < N; i++){
    auto it = upper_bound(x, x + N, x[i] + L);
    next_hotel[0][i] = it - x - 1;
  }

  for(int i = 1; i < 30; i++){
    for(int j = 0; j < N; j++){
      next_hotel[i][j] = next_hotel[i - 1][next_hotel[i - 1][j]];
    }
  }

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; i++){
    int a;
    int b;
    cin >> a >> b;
    if(a > b){
      int tmp = a;
      a = b;
      b = tmp;
    }
    a--;
    b--;
    long long ans = 0;
    int cur_hotel = a;
    for(int j = 29; j >= 0; j--){
      if(next_hotel[j][cur_hotel] < b){
        ans += (1 << j);
        cur_hotel = next_hotel[j][cur_hotel];
      }
    }
    cout << ans + 1 << endl;
  }

  /*
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 30; j++){
      cout << next_hotel[j][i] << " ";
    }
    cout << endl;
  }
  */
  return 0;
}
