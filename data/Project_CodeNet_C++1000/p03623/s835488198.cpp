#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll x, a, b;
        cin >> x >> a >> b;
        ll al = abs(x-a);
        ll bl = abs(x-b);
        if (al < bl) cout << "A" << endl;
        else cout << "B" << endl;


}
