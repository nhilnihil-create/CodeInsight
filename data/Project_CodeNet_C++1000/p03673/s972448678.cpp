#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    deque<ll> out;
    rep(i, n)
    {
        ll a;
        cin >> a;
        if (i % 2 == n % 2)
            out.push_back(a);
        else
            out.push_front(a);
    }
    rep(i, n) cout << out[i] << " ";
    cout << endl;
    return 0;
}