#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll a, b, c; cin >> a >> b >> c;
    set<ll> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout << s.size() << endl;

}
