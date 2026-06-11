#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  char s[222];
  cin >> s;
  int n = strlen(s);
  for(int i=n-2;i>=0;i-=2){
    if(strncmp(s,s+i/2,i/2)==0){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
