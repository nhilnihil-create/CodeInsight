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
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<int> v(3);
    rep(i, n) {
        if (A[i] % 4 == 0) {
            v[2]++;
        }
        else if (A[i] % 2 == 0) {
            v[1]++;
        }
        else {
            v[0]++;
        }
    }

    if (v[1] >= 1) {
        yorn(v[0] <= v[2]);
    }
    else {
        yorn(v[0] - 1 <= v[2]);
    }

    return 0;
}