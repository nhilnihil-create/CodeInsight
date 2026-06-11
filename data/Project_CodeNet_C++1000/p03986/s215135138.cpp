#include<bits/stdc++.h>
using namespace std;
int main(){
  string x;
  cin >> x;
  int ans = 0;
  int s = 0;
  for(auto c:x){
    if(c=='S') s++;
    else if(s == 0) ans++;
    else s--;
  }
  ans += s;
  cout << ans << endl;
}