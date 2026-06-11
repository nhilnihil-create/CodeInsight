#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s,t;
  cin >> s;
  string ans;
  reverse(s.begin(),s.end());
  ll i=0;
  while(1){
    string u;
    bool is=false;
    if(i>=s.size()){
      break;
    }
    u=s.substr(i,5);
    if(u=="maerd" || u=="esare"){
      is=true;
      i+=5;
      continue;
    }
    u=s.substr(i,6);
    if(u=="resare"){
      is=true;
      i+=6;
      continue;
    }
    u=s.substr(i,7);
    if(u=="remaerd"){
      is=true;
      i+=7;
      continue;
    }
    if(!is){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
    