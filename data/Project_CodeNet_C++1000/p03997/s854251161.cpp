#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main(){ 
  int a, b, h;
  cin >> a >> b >> h;
  cout << (a + b) * h / 2 << endl;
  return 0;
} 