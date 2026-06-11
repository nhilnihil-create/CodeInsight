#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
  string s;
  cin >> s;
  int a,b;
  rep(i,s.size()){
    if(s.at(i)=='A'){
      a=i;
      break;
    }
  }
  for(int i=s.size()-1;i>=0;i--){
    if(s.at(i)=='Z'){
      b=i;
      break;
    }
  }
  cout << b-a+1 << endl;
}