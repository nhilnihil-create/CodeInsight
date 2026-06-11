#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int>a(N*3);
  for(int i=0; i<N*3; i++)cin >> a.at(i);
  
  int64_t ans=0;
  sort(a.begin(), a.end());
  
  for(int i=2; i<=2*N; i+=2){
    ans += a.at(3*N-i);
  }
  
  cout << ans << endl;
}