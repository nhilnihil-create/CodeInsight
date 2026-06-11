#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  if(s[0] == '9' || s[1] == '9'){
    puts("Yes");
  }
  else puts("No");
  return 0;
}
