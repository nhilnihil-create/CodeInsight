#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll aMax = 0;
    REP(i, N)
    {
        cin >> A[i];
        if (aMax < A[i])
        {
            aMax = A[i];
        }
    }

    ll G = A[0];
    REP(i, N - 1)
    {
        G = gcd(G, A[i + 1]);
    }
    string ans;
    if (K <= aMax && K % G == 0)
    {
        ans = "POSSIBLE";
    }
    else
    {
        ans = "IMPOSSIBLE";
    }

    cout << ans << endl;
}
