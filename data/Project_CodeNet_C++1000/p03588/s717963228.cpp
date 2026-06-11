#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int,int>> AB(N);
  for(int i=0;i<N;i++)  cin >> AB.at(i).first >> AB.at(i).second;

  sort(AB.begin(),AB.end());
  int ans=AB.at(N-1).first+AB.at(N-1).second;
  cout << ans << endl;

  return 0;
}