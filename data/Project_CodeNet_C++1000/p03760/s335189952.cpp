#include<bits/stdc++.h>
using namespace std;
int main(){
  string o,e;
  cin >> o >> e;
  int m = o.size() + e.size();
  vector<string> ans(m);
  for(int i = 0; i < m; i++){
    if(i%2 == 0){
      ans.at(i) = o.at(i/2);
    }
    else{
      ans.at(i) = e.at((i-1)/2);
    }
  }
  for(int i = 0; i < m-1; i++){
    cout << ans.at(i);
  }
  cout << ans.at(m-1) << endl;

}