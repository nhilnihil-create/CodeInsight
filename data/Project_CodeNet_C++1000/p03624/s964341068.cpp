#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
int main() {
  string s;
  cin>>s;
  set<char>k;
  for(int i=0;i<s.size();i++){
    k.insert(s[i]);
  }
  for(char i='a';i<='z';i++){
    if(!k.count(i)){cout<<i<<endl;return 0;}
  }
  cout<<"None"<<endl;
  return 0;  
}