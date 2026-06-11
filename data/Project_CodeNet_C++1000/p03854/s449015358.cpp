#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);ios::sync_with_stdio(0);
  string s;cin >> s;
  int n = s.size(),i = 0;
  reverse(s.begin(),s.end());
  while(i<n){
    if(s.substr(i,5)=="maerd") i+=5;
    else if(s.substr(i,7)=="remaerd") i+=7;
    else if(s.substr(i,5)=="esare") i+=5;
    else if(s.substr(i,6)=="resare") i+=6;
    else{
      printf("NO\n");return 0;
    }
  }
  printf("YES\n");return 0;
}