#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s,t;
  cin >> s;
  t = s;
  reverse(s.begin(),s.end());
  if(s == t){
    puts("Yes");
  }
  else{
    puts("No");
  }
  return 0;
}
