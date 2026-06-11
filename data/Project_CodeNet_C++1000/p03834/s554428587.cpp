#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  
  int n = s.size();
  rep(i,n){
    if(s[i] == ',') cout << " ";
    else cout << s[i];
  }
  cout << endl;
  return 0; 
}