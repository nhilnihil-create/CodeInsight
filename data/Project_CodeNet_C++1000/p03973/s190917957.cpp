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
long long A[100000];
int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  int cur_price = 1;
  long long ans = 0;
  for(int i = 0; i < N; i++){
    if(A[i] % cur_price != 0){
      ans += (A[i] / cur_price);
    } else {
      ans += (A[i] / cur_price) - 1;
      if(A[i] == cur_price || cur_price == 1){
        cur_price ++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}