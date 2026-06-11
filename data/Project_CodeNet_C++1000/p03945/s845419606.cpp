#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n=s.size();
  char c=s[0];
  int ans=0;
  for(int i=1;i<n;i++){
    if(c!=s[i]){
      ans++;
      c=s[i];
    }
  }
  cout << ans << endl;
}