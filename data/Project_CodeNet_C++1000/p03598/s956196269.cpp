#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int>X(N);
  for(int i=0; i<N; i++){
    cin >> X.at(i);
  }
  
  int ans = 0;
  
  for(int i=0; i<N; i++){
    if(X.at(i)*2<K){
      ans += 2*X.at(i);
    }
    
    else{
      ans += 2*(K-X.at(i));
    }
  }
  
  cout << ans << endl;
}
