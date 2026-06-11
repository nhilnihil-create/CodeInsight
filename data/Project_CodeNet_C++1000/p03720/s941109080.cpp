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
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];

    vector<int> cnt(n);
    rep(i, n) cnt[i] = 0;
    rep(i, m) {
        cnt[a[i] - 1]++;
        cnt[b[i] - 1]++;
    }
    rep(i, n) {
        put(cnt[i]);
    }
    
    return 0;
}