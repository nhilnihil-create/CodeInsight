#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int N;
  cin >> N;
  
  vector<int> A(3*N);
  for(int i=0; i<3*N; i++){
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  int64_t ans=0;
  for(int i=0; i<2*N; i+=2){
    ans += A.at(i+1);
  }
 
  cout << ans << endl;
  
}
