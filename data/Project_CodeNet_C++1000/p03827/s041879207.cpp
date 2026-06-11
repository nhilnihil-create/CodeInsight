#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {
  int N; cin >> N;
  string S; cin >> S;
  int x = 0;
  int ans = 0;
  rep(i,N){
    if(S[i] == 'I') x++;
    else x--;
    ans = max(ans,x);
  }
  cout << ans << endl;
	return 0;
}

