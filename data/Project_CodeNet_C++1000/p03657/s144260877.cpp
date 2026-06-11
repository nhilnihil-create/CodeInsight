#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main() {
  int a, b;
  cin >> a >> b;
  if (a % 3 == 0) {
    cout << "Possible" << endl;
    return 0;
  }
   if (b % 3 == 0) {
    cout << "Possible" << endl;
    return 0;
  }
   if ((a + b) % 3 == 0) {
    cout << "Possible" << endl;
    return 0;
  }
  cout << "Impossible" << endl;
  return 0; 
} 