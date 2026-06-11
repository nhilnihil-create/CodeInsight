#define _USE_MATH_DEFINES
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
long long a[15];
int main(void){
  int N;
  int K;
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  long long ans = LLONG_MAX;
  for(int bit_set = 0; bit_set < (1 << N); bit_set++){
    long long last_height = 0;
    long long tmp_ans = 0;
    int buliding_no = 0;
    for(int i = 0; i < N; i++){
      if(((bit_set >> i) & 1) == 1){
        buliding_no ++;
        if(last_height >= a[i]){
          tmp_ans += (last_height + 1) - a[i];
          last_height = (last_height + 1);
        } else {
          last_height = a[i];
        }
      }
      last_height = max(last_height, a[i]);
    }
    if(buliding_no >= K){
      ans = min(ans, tmp_ans);
      //cout << bit_set << " " << tmp_ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}