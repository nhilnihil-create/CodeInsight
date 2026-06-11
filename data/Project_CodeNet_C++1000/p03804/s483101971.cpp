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
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    vector<string> b(m);
    rep(i, m) cin >> b[i];

    rep(oy, n-m+1) rep(ox, n-m+1) {
        bool found = true;
        rep(dy, m) rep(dx, m) {
            if (a[oy+dy][ox+dx] != b[dy][dx]) {
                found = false;
                break;
            }
        }
        if (found == true) {
            put("Yes");
            return 0;
        }
    }
    
    put ("No");
    return 0;
}