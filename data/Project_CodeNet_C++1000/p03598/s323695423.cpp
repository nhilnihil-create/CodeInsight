#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,ans = 0;
  cin >> N >> K;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    ans += min(vec[i]*2,(K-vec[i])*2);
  }
  cout << ans << endl;
}
