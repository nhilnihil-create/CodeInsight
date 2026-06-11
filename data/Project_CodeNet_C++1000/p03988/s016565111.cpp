#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int d[N]={}; rep(i,N) { int a; cin >> a; d[a]++; }

  string result = "Impossible";
  int l = 0; while(d[l]==0) l++;
  int r = N-1; while(d[r]==0) r--;
  if ((r+1)/2==l) {
    result = "Possible";
    for (int i=l; i<=r; i++) {
      if (i==l) { if (d[i]!=r%2+1)  { result = "Impossible"; break; } }
      else { if (d[i]<=1) { result = "Impossible"; break; } }
    }
  }
  cout << result << endl;
  return 0;
}