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

    vector<int> b1, b2;
    rep(i, n) {
        if ((i + 1) % 2 == 0) {
            b2.push_back(a[i]);
        }
        else {
            b1.push_back(a[i]);
        }
    }

    vector<int> b;
    if (n % 2 == 0) {
        // 偶数奇数
        reverse(all(b2));
        rep(i, b2.size()) b.push_back(b2[i]);
        rep(i, b1.size()) b.push_back(b1[i]);
    }
    else {
        // 奇数偶数
        reverse(all(b1));
        rep(i, b1.size()) b.push_back(b1[i]);
        rep(i, b2.size()) b.push_back(b2[i]);
    }

    rep(i, b.size()) cout << b[i] << (i == b.size() - 1 ? "" : " ");

    cout << endl;

    return 0;
}