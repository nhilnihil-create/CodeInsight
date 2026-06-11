#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    
    int m;
    cin >> m;
    vector<int> p(m), x(m);
    rep(i, m) cin >> p[i] >> x[i];

    int sum = accumulate(all(t), 0);
    rep(i, m) {
        put(sum - (t[p[i] - 1] - x[i]))
    }

    
    return 0;
}