#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int ans;
  int n=s.length();
  for(int i=n;i>0;i--){
    if(s[i]=='Z'){
      ans=i;
      break;
    }
  }
  for(int i=0;i<n-1;i++){
    if(s[i]=='A'){
      ans-=i;
      break;
    }
  }
  cout << ans+1 << endl;
}
