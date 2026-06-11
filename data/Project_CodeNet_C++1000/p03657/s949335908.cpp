#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
  int A, B;
  cin >> A >> B;
  if(A%3==0 || B%3==0 || (A+B)%3==0) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
