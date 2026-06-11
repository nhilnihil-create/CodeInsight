#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N+1,0);
  for (int i=1; i<N+1; i++){
    cin >> A.at(i); 
  }
  int i = 1;
  int mi = 0;
  int ans = 0;
  while (i != 2){
    ans++;
    mi = i;
    i = A.at(i);
    A.at(mi) = 1;
    if (A.at(i) == 1 && i != 2){
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
}