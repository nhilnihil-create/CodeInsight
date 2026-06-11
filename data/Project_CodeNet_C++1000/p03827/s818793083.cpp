#include<bits/stdc++.h>
using namespace std;

int main(){
 int n;
 cin >> n;
 string s;
 cin >> s;
  int ans = 0;
  int maxans = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'I') ans ++;
    else ans--;
    maxans = max(ans,maxans);
  }
  cout << maxans;
  return 0;
}