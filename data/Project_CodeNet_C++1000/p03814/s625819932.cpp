#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int a1,a2;
  int ans;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A'){ a1 = i; break; }
  }
  for(int i = s.size() - 1; i >= 0; i--){
    if(s[i] == 'Z') { a2 = i; break; }
  }
  cout << a2 - a1 + 1 << endl;
}