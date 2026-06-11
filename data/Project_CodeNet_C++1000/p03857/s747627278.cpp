#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int N, K, L;
vector<int> uf1, uf2;

int main()
{
    cin >> N >> K >> L;
    uf1.resize(N+1);
    uf2.resize(N+1);
    for (int i=1; i<=N; i++) uf1[i] = uf2[i] = i;

    for (int i=0; i<K; i++)
    {
        int p, q;
        cin >> p >> q;
        while (p != uf1[p]) p = uf1[p];
        while (q != uf1[q]) q = uf1[q];
        uf1[q] = uf1[p] = min(uf1[p], uf1[q]);
    }
    for (int i=0; i<L; i++)
    {
        int p, q;
        cin >> p >> q;
        while (p != uf2[p]) p = uf2[p];
        while (q != uf2[q]) q = uf2[q];
        uf2[q] = uf2[p] = min(uf2[p], uf2[q]);
    }
    map<P, int> m;
    for (int i=1; i<=N; i++)
    {
        int p = uf1[i], q = uf2[i];
        while (p != uf1[p]) p = uf1[p];
        while (q != uf2[q]) q = uf2[q];
        m[make_pair(p, q)]++;
    }
    for (int i=1; i<=N; i++)
    {
        int p = uf1[i], q = uf2[i];
        while (p != uf1[p]) p = uf1[p];
        while (q != uf2[q]) q = uf2[q];
        cout << m[make_pair(p, q)] << " ";
    }
    cout << endl;
}
