#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    ll ans = 0;
    ll prev = 0;
    for (ll i = N - 1; i >= 0; --i)
    {
        A[i] += prev;
        if (A[i] % B[i] != 0)
        {
            ans += B[i] - (A[i] % B[i]);
            prev += B[i] - (A[i] % B[i]);
        }
    }

    cout << ans << endl;
}
