#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;


int main() {
  int N;
  cin >> N;
  vector<int> AN(N);
  REP(n,N) cin >> AN[n];

  int dist = 100000000;
  int ans = 100000000;
  for (int num = -100; num <= 100; num++){
    int tmp = 0;
    REP(n,N) tmp += (AN[n]-num)*(AN[n]-num);
    if (tmp < dist){
      dist = tmp;
      ans = num;
    }
  }

  cout << dist << endl;
}
