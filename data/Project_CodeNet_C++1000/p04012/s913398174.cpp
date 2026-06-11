#include<bits/stdc++.h>

using namespace std;

void solve(){
  string s;
  cin >> s;
  map < int , int > m;
  for(int i = 0; i < 36; i++){
    m[i] = 2;
  }
  for(int i = 0; i < s.size(); i++){
    int t = s[i] - 'a';
    m[t]++;
  }
  int flag = 0;
  for(int i = 0; i < 36; i++){
    if(m[i] % 2 == 1){
      flag = 1;
    }
  }
  if(flag == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}

int main(){
  solve();
}