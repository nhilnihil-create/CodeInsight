#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    ll cur1=0, cur2=0;
    ll a1=0, a2=0;
    for (int i=0; i<n; ++i) {
        cur1+=a[i];
        cur2+=a[i];
        if (i%2==0) {
            if (cur1>=0) {
                a1+=cur1+1;
                cur1=-1;
            }
            if (cur2<=0) {
                a2+=-cur2+1;
                cur2=1;
            }
        } else {
            if (cur1<=0) {
                a1+=-cur1+1;
                cur1=1;
            }
            if (cur2>=0) {
                a2+=cur2+1;
                cur2=-1;
            }
        }
    }
    cout << min(a1, a2);
    return 0;
}