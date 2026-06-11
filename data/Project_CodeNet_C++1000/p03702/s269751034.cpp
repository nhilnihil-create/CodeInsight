// LHIC code
#include <bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
 
 
typedef long long ll;
typedef long long llong;
typedef long double ld;
 
using namespace std;
 
template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
 
int n;
ld a, b;
ld h[120000];
 
int main() {
    cin >> n >> a >> b;
    a -= b;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    ld l = 0;
    ld r = 1e9;
    while (r - l > 1) {
        ld mid = ceil((ld)(l + r)/(ld)2);
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
			if (h[i] > mid * b) {
                cnt += ceil(ld(h[i] - mid * b) / (ld)a);
            }
        }
        if (cnt <= mid)
            r = mid;
        else
            l = mid;
    }
    cout << (int)ceil(r) << "\n";
    return 0;
}