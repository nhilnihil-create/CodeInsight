#include <bits/stdc++.h>
using namespace std;
int m, n;
const int N = 200;
int ai[N], c;
int main()
{
    cin >> m >> n;
    if (n == 1)
    {
        int a;
        cin >> a;
        if (a == 1) cout << 1 << endl << 1 << endl << 1 << endl;
        else cout << a << endl << 2 << endl << a - 1 << " " << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++ i)
        cin >> ai[i], c += ai[i] & 1;
    if (c > 2)
    {
        cout << "Impossible\n";
        return 0;
    }
    int A = 1, B = 2;
    for (int i = 3; i <= n; ++ i)
        if (ai[i] & 1)
        {
            A = i;
            for (int j = i + 1; j <= n; ++ j)
                if (ai[j] & 1)
                {
                    B = j;
                    goto GG;
                }
            goto GG;
        }
    GG:
    cout << ai[A] << " ";
    for (int i = 1; i <= n; ++ i) if (i != A && i != B) cout << ai[i] << " ";
    cout << ai[B] << endl;
    if (ai[A] == 1) cout << n - 1 << endl;
    else  cout << n << endl << ai[A] - 1 << " ";
    for (int i = 1; i <= n; ++ i) if (i != A && i != B) cout << ai[i] << " ";
    cout << ai[B] + 1 << endl;
}
