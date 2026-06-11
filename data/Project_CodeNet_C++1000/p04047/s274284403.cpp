#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, n) ;for (int i = 0;i < (int)(n);i++)
#define rep2(i, s, n) ;for (int i = s; i < (int)(n);i++)
#define ALL(vec)  (vec).begin(),(vec).end()
#define pi 3.1415926535897932384626433832795
#define MAX_INF 9223372036854775807
#define MIN_INF (922337203685477587+1)
#define sosuu 1000000007

int main() {
  int N;
  cin >> N;
  vector<int> L(2*N);
  rep(i, 2*N)
    cin >> L[i];
  sort(ALL(L));
  int ans=0;
  rep(i, N){
  ans+=L[2*i];
  }
  cout << ans << endl;
}
