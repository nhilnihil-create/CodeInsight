#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n;
  cin >> n;
  const int NMAX = 100005;
  vector<int> sum(NMAX) ;
  REP(i,n){
    int a;
    cin >> a;
    sum[a]++;
  }
  int cmax = 0;
  REP2(i,1,NMAX-1){
    int tmp = sum[i-1]+sum[i]+sum[i+1];
    cmax = max(tmp,cmax);
  }

  cout << cmax << endl;
  return 0;
}
