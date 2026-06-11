#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> leg(N);
  for (int i=0; i < N ; i++){
    cin >> leg.at(i);
  }
  sort(leg.begin(), leg.end(), greater<int>());
  int ans =0;
  for (int i=0; i < K ; i++){
    ans += leg.at(i);
  }
  
  cout << ans << endl;
} 
