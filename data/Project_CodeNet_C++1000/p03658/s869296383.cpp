#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, k;
  cin >> n >> k;
  vector<int> l(n);

  REP(i,n) cin >> l[i];

  sort(RALL(l));
  int sum = 0;
  REP(i,k){
    sum += l[i];
  }

  cout << sum << endl;
  return 0;
}
