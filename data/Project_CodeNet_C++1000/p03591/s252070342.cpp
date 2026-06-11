#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  if(s.substr(0,4) == "YAKI"){
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}
