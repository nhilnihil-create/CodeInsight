#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> a(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> a[i];
        }
        vector<ll> o;
        vector<ll> e;
        for (int i = 0; i < N; ++i) {
                if (i % 2) {
                        o.push_back(a[i]);
                }
                else {
                        e.push_back(a[i]);
                }
        }
        vector<ll> b;
        for (int i = o.size(); i > 0; --i) {
                b.push_back(o[i-1]);
        }
        for (int i = 0; i < e.size(); ++i) {
                b.push_back(e[i]);
        }
        if (N % 2 == 0) {
                for (int i = 0; i < N; ++i) {
                        cout << b[i] << " ";
                }
        }
        else {
                for (int i = N; i > 0; --i) {
                        cout << b[i-1] << " ";
                }
        }
        cout << endl;

}
