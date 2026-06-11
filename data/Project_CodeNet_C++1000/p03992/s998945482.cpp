#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  for(int i = 0; i < 12; i++){
    cout << s[i];
    if(i == 3) cout << " ";
  }
  cout << endl;  
  return 0;
}