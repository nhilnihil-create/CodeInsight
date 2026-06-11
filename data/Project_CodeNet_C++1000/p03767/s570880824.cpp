#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<long> a(3*N);
  for (int i=0; i < 3*N ; i++){
    cin >> a.at(i);
  }
  sort(a.begin(), a.end(), greater<int>());
  
  vector<vector<long>> team(N,vector<long> (3));
  int k=0;
  for (int i = 0; i < N; i++){
    for (int j=0; j < 2 ; j++){
      team.at(i).at(j) = a.at(k);
      k++;
    }
  }
  
  long ans =0;
  for (int i=0; i<N ; i++){
    ans += team.at(i).at(1);
  }
  
  cout << ans << endl;
}
