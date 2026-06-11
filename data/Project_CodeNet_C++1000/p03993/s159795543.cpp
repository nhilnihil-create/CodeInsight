#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> v(N+1);
  for(int i=1;i<=N;i++){
    cin >> v.at(i);
  }
  int ans=0;
  for(int i=1;i<=N;i++){
    if(v.at(v.at(i))==i){
      ans++;
    }
  }
  ans/=2;
  cout << ans << endl;
  return 0;
}
