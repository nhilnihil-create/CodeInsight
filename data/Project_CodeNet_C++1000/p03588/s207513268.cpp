#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> vec(N,vector<int>(2));
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin >> vec.at(i).at(j);
    }
  }
  sort(vec.begin(),vec.end());
  int ans = 0;
  ans += vec.at(N-1).at(0) - vec.at(0).at(0) +1;
  ans += vec.at(0).at(0) - 1;
  ans += vec.at(N-1).at(1);
  cout << ans << endl;
}