#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;



int main() {
  int N; cin >> N;

  int ans = 1;
  int c = 0;
  for(int i = 1; i <= N; i++){
    int e = 0;
    int j = i;
    while(true){
      if (j % 2 != 0) break;
      e++;
      j /= 2;
    }
    if ( c < e) {
      c = e;
      ans = i;
    }
  }

  cout << ans << endl;


  return 0;
}






