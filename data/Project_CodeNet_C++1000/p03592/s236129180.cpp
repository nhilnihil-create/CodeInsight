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
  int n, m, k;
  cin >> n >> m >> k;
  REP(i,n+1)REP(j,m+1){
    int sum = 0;
    sum = i*m + j*n - 2*i*j;
    //cout <<i <<" " <<  j<< " " << sum << endl;
    if(sum == k){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
