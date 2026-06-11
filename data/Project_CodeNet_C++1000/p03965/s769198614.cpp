#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0;i < s.size();i++){
    if(s.at(i) == 'p'){
      if(i % 2 == 0) ans--;
    }
    else{
      if(i % 2 != 0) ans++;
    }
  }
  cout << ans << endl;
}