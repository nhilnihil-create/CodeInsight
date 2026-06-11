#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  sort(A.begin(), A.end());
  
  int ans=N;
  int64_t ookisa = A.at(0);
  int count =1;
  for(int i=1; i<N; i++){
    if(ookisa *2 >=A.at(i)){
      ookisa += A.at(i);
      count ++;
    }
    else{
      ans -= count;
      count =1;
      ookisa +=A.at(i);
    }
  }
  
  cout << ans << endl;
}