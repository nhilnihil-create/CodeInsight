#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    sort(all(s));

    int sum = accumulate(all(s), 0);
    if (sum % 10 != 0) {
        put(sum);
        return 0;
    }

    rep (i, s.size()) {
        if (s[i] % 10 != 0) {
            sum -= s[i];
            break;
        }
    }

    put((sum % 10 == 0 ? 0 : sum));

    return 0;
}