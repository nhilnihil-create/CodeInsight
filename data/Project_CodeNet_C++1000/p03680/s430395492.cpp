#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    A.at(i)--;
  }
  
  vector<bool> passed(N, false);
  int now = 0, ans = 0;
  while (passed.at(now) == false){
    passed.at(now) = true;
    now = A.at(now);
    ans++;
    if (now == 1){
      cout << ans << endl;
      exit(0);
    }
  }
  
  cout << "-1" << endl;
}