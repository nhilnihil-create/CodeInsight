#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int func(int a, int b, int c){
  if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1) return 0;
  if(a == b && b == c) return -1;
  int cnt = 0;
  while(true){
    if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1) break;
    int aa = b / 2 + c / 2;
    int bb = a / 2 + c / 2;
    int cc = a / 2 + b / 2;
    a = aa, b = bb, c = cc;
    cnt++;
  }
  return cnt;
}


int main(){
  int a,b,c; cin >> a >> b >> c;
  int ans = func(a,b,c);
  cout << ans << endl;
  return 0;
}
