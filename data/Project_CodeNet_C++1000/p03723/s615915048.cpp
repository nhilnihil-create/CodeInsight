#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;

    if (A == B && B == C && A % 2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0)
    {
        ll halfA = A / 2, halfB = B / 2, halfC = C / 2;
        A = halfB + halfC;
        B = halfA + halfC;
        C = halfA + halfB;
        ans++;
    }

    cout << ans << endl;
}
