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
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    sort(all(A));
    reverse(all(A));

    vector<ll> v;
    rep(i, n - 1) {
        if (A[i] == A[i + 1]) {
            v.push_back(A[i]);
            i++;
            if (v.size() >= 2) {
                break;
            }
        }
    }

    if (v.size() < 2) {
        put(0);
    }
    else {
        put(v[0] * v[1])
    }

    return 0;
}