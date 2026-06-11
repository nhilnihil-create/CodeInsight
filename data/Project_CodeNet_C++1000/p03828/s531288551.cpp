#include <bits/stdc++.h>
using namespace std;

#define     ll     long long int

ll mod = 1000000007;

map<int, int> mp;
map<int, int>::iterator it;

void get(int n)
{
    int i, j, rt = sqrt(n);
    for (i = 2; i <= rt; i++) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                n /= i;
                c++;
            }
            mp[i] += c;
        }
    }
    if (n > 1) {
        mp[n]++;
    }
}

int main( )
{
    int i, j, k, n;
    cin >> n;
    for (i = 2; i <= n; i++) {
        get(i);
    }
    ll ans = 1;
    for (it = mp.begin(); it != mp.end(); it++) {
        j = (*it).second;
        ans = (ans * (j + 1)) % mod;
    }
    cout << ans << '\n';
    return 0;
}
