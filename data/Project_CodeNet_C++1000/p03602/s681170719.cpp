#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int> > A(N, vector<int>(N));
    for (int i=0; i<N*N; i++) cin >> A[i/N][i%N];

    vector<vector<bool> > need(N, vector<bool>(N, true));
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            for (int k=0; k<N; k++)
            {
                if (k==i || k==j) continue;
                if (A[i][k] + A[k][j] < A[i][j])
                {
                    cout << -1 << endl; return 0;
                }
                else if (A[i][k] + A[k][j] == A[i][j])
                {
                    need[i][j] = false;
                }
            }
        }
    }
    long long ans = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            if (need[i][j]) ans += A[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}