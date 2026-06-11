#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{

    ll N;
    cin >> N;
    ll maxindex = 0;
    ll num = 0;
    for (ll i = 0; i < N; ++i)
    {
        ll A, B;
        cin >> A >> B;
        if (maxindex < A)
        {
            maxindex = max(maxindex, A);
            num = B;
        }
    }
    cout << num + maxindex << endl;
}
