#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    z = 0;
    if (i && j && l)z = (i - 1) / 2 * 2 + o + (j - 1) / 2 * 2 + (l - 1) / 2 * 2 + 3;
    cout << max(i / 2 * 2 + o + j / 2 * 2 + l / 2 * 2, z) << endl;

 }