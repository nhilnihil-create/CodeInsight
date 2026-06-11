#include <bits/stdc++.h>

#define ln "\n"
#define SORT(X) sort(X.begin(), X.end())
#define SORTi(X) sort(X.begin(), X.end(), greater<ll>())
#define REP(x, a, b) for (auto x = a; x <= b; x++)
#define REPi(x, b, a) for (auto x = b; x >= a; x--)
#define REPit(x, A) for (auto x = A.begin(); x != A.end(); x++)
#define REPr(x, A) for (auto x : A)
#define ll long long
#define ull unsigned long long
#define PB push_back
#define EB emplace_back
#define UMP unordered_map
#define UST unordered_set

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N = 0;
    cin >> N;
    ll sum = 0;
    vector<ll> A(N);
    REP(i, 0, N - 1)
    {
        cin >> A[i];
        sum = sum + A[i];
    }
    SORT(A);
    if (sum % 10 == 0)
    {
        REP(i, 0, N-1)
        {
            if (A[i] % 10 != 0)
            {
                sum = sum - A[i];
                cout<<sum;
                return 0;
            }
        }
    }
    if (sum % 10 == 0)
        cout << 0 << ln;
    else
        cout << sum << ln;
    return 0;
}