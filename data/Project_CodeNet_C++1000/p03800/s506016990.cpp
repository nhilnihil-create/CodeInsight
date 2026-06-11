#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<char> s(n + 2);
  for(int i = 0; i < n; i++) cin >> s[i];
  s[n] = s[0];
  s[n + 1] = s[1];
  
  vector<char> a(n + 2);
  for(int b = 0; b < (1 << 2); b++){
    a[0] = (b & 1) ? 'W' : 'S';
    a[1] = (b & (1 << 1)) ? 'W' : 'S';
    for(int i = 2; i <= n + 1; i++){
      if(s[i - 1] == 'o'){
        if(a[i - 1] == 'S'){
          a[i] = a[i - 2];
        }else{
          a[i] = (a[i - 2] == 'S') ? 'W' : 'S';
        }
      }else{
        if(a[i - 1] == 'W'){
          a[i] = a[i - 2];
        }else{
          a[i] = (a[i - 2] == 'S') ? 'W' : 'S';
        }
      }
    }
    if(a[0] == a[n] && a[1] == a[n + 1]){
      for(int i = 0; i < n; i++){
        cout << a[i];
      }
      cout << '\n';
      break;
    }
  }
  
  if(a[0] != a[n] || a[1] != a[n + 1]) cout << -1 << '\n';
  
  return 0;
}