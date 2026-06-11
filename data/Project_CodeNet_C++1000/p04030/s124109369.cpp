#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  string t;
  for(int i=0;i<n;i++){
    if(s[i]=='B'){
      if(!t.empty()){t.pop_back();}
    }
    else{t.push_back(s[i]);}
  }
  cout<<t<<endl;
  return 0;  
}