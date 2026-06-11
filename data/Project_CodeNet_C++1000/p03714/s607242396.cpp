#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main () {

  int N; cin >> N;
  vector<int> a(3*N);

  for (int i = 0; i < 3 * N; i++ ) {
    cin >> a[i];
  }

  priority_queue<int> pqr;
  priority_queue<int, vector<int>, greater<int> > pql;
  vector<ll> vl(N+1, 0), vr(N+1, 0);
  for (int i = 0; i < N; i++ ) {
    pql.push(a[i]);
    pqr.push(a[3*N-i-1]);

    vl[0] += a[i];
    vr[N] += a[3*N-i-1];
  }

  for (int i = N; i < 2*N; ++i ) {

    vl[i-N+1]   = vl[i-N];
    vr[2*N-i-1] = vr[2*N-i];

    int l = pql.top();
    if (a[i] > l) {
      pql.pop();
      pql.push(a[i]);
      vl[i-N+1] += a[i]-l;
    }

    int r = pqr.top();
    if (a[3*N-i-1] < r) {
      pqr.pop();
      pqr.push(a[3*N-i-1]);
      vr[2*N-i-1] -= r - a[3*N-i-1];
    }

  }

  /*
  for (int i = 0; i <= N; ++i ) 
    cout << vl[i] << " ";
  cout << endl;

  for (int i = 0; i <= N; ++i ) 
    cout << vr[i] << " ";
  cout << endl;
  */

  ll ans = LLONG_MIN;
  for (int i = 0; i <= N; ++i ) 
    ans = max(ans, vl[i]-vr[i]);

  cout << ans << endl;

  return 0;
}
