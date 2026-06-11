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
  int N; cin >> N;
  vector <int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  string ans = "Yes";

  if (A[N - 1] - A[0] > 1){
    ans = "No";
  }else if(A[N - 1] - A[0] == 1){
    int cnt = 0;
    for (int i = 0; i < N; i++){
      if(A[i] == A[0]) cnt++;
    }
    
    if (cnt >= A[N - 1]){
      ans = "No";
    }else if(2 * (A[N - 1] - cnt) > N - cnt){
      ans = "No";
    }

  }else{
    if (2 * A[N - 1] > N && A[0] + 1 != N){
      ans = "No";
    }    
  }
  
  cout << ans << endl;

  return 0;
}
