#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);

  ll INF = 10000000000000000;
  ll A,B;
  cin >> A >> B;

  ll ans = 0;
  ll tmp1,tmp2,tmp3,tmp4;

  // BB
  tmp1 = 1 + (-B-(-A)) + 1;
  tmp1 = (tmp1 >= 0 ? tmp1 : INF);
  // B-
  tmp2 = 1 + B - (-A);
  tmp2 = (tmp2 >= 0 ? tmp2 : INF);
  // -B
  tmp3 = -B -A + 1;
  tmp3 = (tmp3 >= 0 ? tmp3 : INF);
  // --
  tmp4 = B-A;
  tmp4 = (tmp4 >= 0 ? tmp4 : INF);


  cout << min(min(tmp1,tmp2), min(tmp3,tmp4)) << endl;
}
