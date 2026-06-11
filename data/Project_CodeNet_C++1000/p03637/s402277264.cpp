#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> a(N, 0);
        ll wari4 = 0;
        ll wari2 = 0;
        ll elc = 0;
        for (int i = 0; i < N; ++i) {
                ll a; cin >> a;
                if (a % 4 == 0) wari4++;
                else if (a % 2 == 0) wari2++;
                else elc++;
        }
        if (wari2) {
                elc++;
                wari2 = 0;
        }
        if (wari4 >= (elc -1)) {
                cout << "Yes" << endl;
        }
        else {
                cout << "No" << endl;
        }
}
