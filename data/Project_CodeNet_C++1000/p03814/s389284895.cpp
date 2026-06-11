#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
string s;
cin >> s;
bool flag = true;
  int x,y;
rep(i,s.size()){
  if(s.at(i) == 'A' && flag){
    x = i;
    flag = false;
  }
  else if(s.at(i) == 'Z') {
    y = i;
  }
}
int ans = y-x+1;
cout << ans << endl;
}
