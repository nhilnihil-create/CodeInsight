#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 1;
  cin >> n;
  while(1){
    if(ans*2 > n) break;
    ans *= 2;
  }
  cout << ans << endl;
}