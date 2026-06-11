#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> t(n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> t.at(i) >> a.at(i);
      	//cout << t.at(i) << ' ' << a.at(i) << endl;
    }

    vector<ll> x(n);
    x.at(0) = 1;
    for (int i = 1; i < n; i++) {
        x.at(i) = max( ( (t.at(i-1) * x.at(i-1) + t.at(i)-1) / t.at(i) ), (a.at(i-1) * x.at(i-1) + a.at(i)-1) / a.at(i)) ;
    	//cout << x.at(i) << endl;
    }

    ll ans = (t.at(n-1) + a.at(n-1)) * x.at(n-1);
    cout << ans << endl;
    return 0;
}