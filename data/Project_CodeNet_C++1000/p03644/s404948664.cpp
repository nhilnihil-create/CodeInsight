#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int ans = 0;
  int counter =0;
  for (int i=1; i <= N; i++){
    int K = i;
    int tempAns = 0;
    while(K > 1){
      if (K%2 == 0){
        K /= 2;
        tempAns++;
      }
      else break;
    }
    if (tempAns > counter) counter = tempAns;
  }
  ans = pow(2, counter);
  cout << ans << endl;

  return 0;
}
