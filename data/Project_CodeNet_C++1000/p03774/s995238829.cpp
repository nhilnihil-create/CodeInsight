#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> Nx(N), Ny(N), Mx(M), My(M);
    for (int i = 0; i < N; i++)
        cin >> Nx[i] >> Ny[i];
    for (int i = 0; i < M; i++)
        cin >> Mx[i] >> My[i];

    for (int i = 0; i < N; i++)
    {
        int ans, d = MOD;
        for (int j = 0; j < M; j++)
        {
            int tmp = abs(Nx[i] - Mx[j]) + abs(Ny[i] - My[j]);
            if (tmp < d)
                ans = j, d = tmp;
        }
        cout << ans + 1 << endl;
    }
}