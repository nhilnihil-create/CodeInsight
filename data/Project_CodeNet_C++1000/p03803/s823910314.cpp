#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  if(a == 1) a += 13;
  if(b == 1) b += 13; 
  if(a == b) puts("Draw");
  if(a > b) puts("Alice");
  if(a < b) puts("Bob");
  return 0;
}
