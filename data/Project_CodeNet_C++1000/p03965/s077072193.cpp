#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans = 0;
  int i;
  for(i=0;i<s.length();i++){
    if(i%2==0){
      if(s[i] == 'p')ans--;
    }else{
      if(s[i] == 'g')ans++;
    }
  }
  cout << ans << endl;
}
