#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int wh[Maxn];
int n;
set <int> S;
ll res;

int main()
{
    scanf("%d", &n);
    S.insert(0); S.insert(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        wh[a] = i;
    }
    for (int i = 1; i <= n; i++) {
        int ind = wh[i];
        auto it2 = S.upper_bound(ind);
        auto it1 = it2; it1--;
        res += ll(ind - *it1) * ll(*it2 - ind) * i;
        S.insert(ind);
    }
    cout << res << endl;
    return 0;
}
