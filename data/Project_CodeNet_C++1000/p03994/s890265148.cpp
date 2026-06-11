#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, k, i, pn;
    string s;

    cin >> s;
    scanf("%d", &k);

    n = s.size();
    i = 0;
    while (i < n - 1)
    {
        if (s[i] != 'a')
        {
            pn = 'z' - s[i] + 1;
            if (pn <= k)
            {
                s[i] = 'a';
                k -= pn;
            }
        }
        i++;
    }

    if (k > 0)
    {
        s[n - 1] = (s[n - 1] - 'a' + k % 26) % 26 + 'a';
    }

    cout << s << '\n';

    return 0;
}