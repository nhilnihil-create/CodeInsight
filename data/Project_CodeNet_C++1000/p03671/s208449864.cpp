#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define numrep(i,n) for(int i=1;i<=n;i++)
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)
#define ll int64_t
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;

int main() {

vector<ll> A(3);

rep(i,3) cin >> A[i];

sort(all(A));

cout << A[0]+A[1] << endl;

return 0;

}