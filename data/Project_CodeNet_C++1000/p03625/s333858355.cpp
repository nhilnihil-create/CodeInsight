#include <bits/stdc++.h>
using  namespace std;

#define    ll     long long int

int main( )
{
    int n, i, j, k, mx = -1;
    map<int, int> mp;
    vector<int> v;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> j;
        mp[j]++;
        if (mp[j] == 2) {
            v.push_back(j);
            mp[j] = 0;
        }
    }
    sort(v.begin(), v.end());
    k = (int) v.size();
    if (k < 2) {
        cout << "0\n";
    }
    else {
        cout << ( (ll) v[k - 1] * v[k - 2]) << '\n';
    }
    return 0;
}