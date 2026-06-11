#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M;
string S, T;
int ps[MAXN], ps2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> S >> T;
    N = S.length();
    M = T.length();

    for (int i = 0; i < N; i++)
        ps[i+1] = ps[i] + (S[i] - 'A' + 1);
    for (int i = 0; i < M; i++)
        ps2[i+1] = ps2[i] + (T[i] - 'A' + 1);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((ps[b] - ps[a-1]) % 3 == (ps2[d] - ps2[c-1]) % 3)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}