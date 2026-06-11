#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    bool flag = false;
    REP(i, N)
    {
        ll minSum = -D * i + C * (N - 1 - i);
        ll maxSum = -C * i + D * (N - 1 - i);
        if (minSum <= B - A && maxSum >= B - A)
        {
            flag = true;
            break;
        }
    }
    string ans = flag ? "YES" : "NO";

    cout << ans << endl;
}
