#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  int ans = vec[0];
  if(vec[0] == 2){
    cout << 1 << endl;
    return 0;
  }
  for(int i=0; i<N; i++){
    ans = vec[ans-1];
    if(ans == 2){
      cout << i+2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
