#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  int x=0, y=0, z=0;
  char nxt='a';
  while(nxt!='z') {
    if(nxt=='a') {
      if(x==a.size()) break;
      nxt=a[x];
      x++;
    }
    else if(nxt=='b') {
      if(y==b.size()) break;
      nxt=b[y];
      y++;
    }
    else if(nxt=='c') {
      if(z==c.size()) break;
      nxt=c[z];
      z++;
    }    
  }
  cout << (char)(nxt-'a'+'A') << endl;
  return 0;
}