#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> score(n,0);
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> score.at(i);
    ans += score.at(i);
  }
  
  sort(score.begin(),score.end());
  for(int i = 0; i < n; i++){
    if(ans % 10 != 0){
      cout << ans << endl;
      return 0;
    }
    else{
      if(score.at(i) % 10 != 0){
      ans = ans - score.at(i);
      }
    }
  }
  if(ans % 10 == 0){
    cout << 0 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}