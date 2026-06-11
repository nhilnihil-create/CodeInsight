#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  string s1 = "dream", s2 = "dreamer", s3 = "erase", s4 = "eraser";
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  reverse(s3.begin(), s3.end());
  reverse(s4.begin(), s4.end());
  
  string t;
  while(true){
    if(s == "") break;
    if(s == t) break;
    t = s;
    if(s.substr(0, 5) == s1) s.erase(0, 5);
    if(s.substr(0, 7) == s2) s.erase(0, 7);
    if(s.substr(0, 5) == s3) s.erase(0, 5);
    if(s.substr(0, 6) == s4) s.erase(0, 6);
  }
  if(s == "") cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}