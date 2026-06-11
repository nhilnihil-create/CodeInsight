#include <bits/stdc++.h>

using namespace std;

#define N 100002
char s[N], t[N];

int n,m,a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> (s+1) >> (t+1);

    n = strlen(s+1);
    m = strlen(t+1);
    for (int i=1; i<=n; i++)
        a[i] = a[i-1] + (s[i] == 'A');
    for (int i=1; i<=m; i++)
        b[i] = b[i-1] + (t[i] == 'A');
    int q; cin >> q;
    while(q--)
    {
        int x,u,y,v; cin >> x >> y >> u >> v;
        int sa = a[y] - a[x-1]; int sb = y-x+1-sa;
        int ta = b[v] - b[u-1]; int tb = v-u+1-ta;
        if (((sa + sb * 2) - (ta + tb*2) % 3 == 0) || ((sa*2 + sb - ta*2 - tb) % 3 == 0)) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    return 0;
}
