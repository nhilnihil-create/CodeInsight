#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int x = 0;
  int max = 0;
  rep(i,n){
    if(s[i] == 'I') x++;
    if(s[i] == 'D') x--;
    if(x>max) max = x;
  }
  
  cout << max << endl;
}