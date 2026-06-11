#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  int N, X; cin >> N >> X;

  if (X == 1 || X == 2 * N - 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;

    vector <int> ans(2 * N - 1);
    vector <bool> checked(2 * N);

    ans[N - 1] = X; checked[X] = true;
    ans[N - 2] = 2 * N - 1; ans[N] = 1;
    checked[2 * N - 1] = true; checked[1] = true;

    if (checked[2 * N - 2] == false && N > 2){
      checked[2 * N - 2] = true;
      ans[N - 3] = 2 * N - 2;
    }
    if (checked[2] == false && N > 2){
      checked[2] = true;
      ans[N + 1] = 2;
    }
    
    int now = 1;
    for (int i = 0; i < 2 * N - 1; i++){
      if (ans[i] == 0){
        while (checked[now] != false){
          now++;
        }
        ans[i] = now;
        checked[now] = true;
      }
    }
    
    for (int i = 0; i < 2 * N - 1; i++){
      cout << ans[i] << endl;
    }
    

  }
  
  return 0;
}