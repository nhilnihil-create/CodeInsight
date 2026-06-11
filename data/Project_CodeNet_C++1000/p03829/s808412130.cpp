#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n);

    for (int &k : x)
        cin >> k;

    ll fatigue = 0;
    for (int i = 0; i < n - 1; ++i)
        fatigue += min((ll)(x[i + 1] - x[i]) * a, (ll)b);

    cout << fatigue << '\n';

    return 0;
}