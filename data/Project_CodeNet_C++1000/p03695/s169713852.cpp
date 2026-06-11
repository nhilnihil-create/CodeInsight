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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> C(8);
    int over=0;
    rep(i, n) {
        if (a[i] <= 399) {
            C[0]++;
        }
        else if (a[i] <= 799) {
            C[1]++;
        }
        else if (a[i] <= 1199) {
            C[2]++;
        }
        else if (a[i] <= 1599) {
            C[3]++;
        }
        else if (a[i] <= 1999) {
            C[4]++;
        }
        else if (a[i] <= 2399) {
            C[5]++;
        }
        else if (a[i] <= 2799) {
            C[6]++;
        }
        else if (a[i] <= 3199) {
            C[7]++;
        }
        else {
            over++;
        }
    }

    int res = 0;
    rep(i, C.size()) {
        if (C[i] > 0) {
            res += 1;
        }
    }

    int low = res;
    if (over >= 1) {
        low = max(res, 1);
    }
    int up = res + over;

    cout << low << " " << up  << endl;

    return 0;
}