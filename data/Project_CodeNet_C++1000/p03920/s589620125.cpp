#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int main(){
  int n;

  scanf("%d", &n);

  int i = 1;
  int a = 0;
  vector<int> v;
  while(a < n) {
    a += i;
    v.push_back(i);
    i++;
  }

  if (a != n) {
    v.erase(remove(v.begin(), v.end(), a - n), v.end());
  }
  REP (i, v.size()) printf("%d\n", v[i]);
}
