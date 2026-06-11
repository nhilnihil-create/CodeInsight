#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S,T;
  cin >> S >> T;
  int N = S.size();
  int M = T.size();
  int R1[N+1];
  int R2[M+1];
  R1[0] = 0; R2[0] = 0;
  for (int i = 0; i < N; i++) {
    int c = S[i] - 'A' + 1;
    R1[i+1] = R1[i] + c;
  }
  for (int i = 0; i < M; i++) {
    int c  = T[i] - 'A' + 1;
    R2[i+1] = R2[i] + c; 
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x = R1[b] - R1[a-1];
    int y = R2[d] - R2[c-1];
    if (x%3 == y%3) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}