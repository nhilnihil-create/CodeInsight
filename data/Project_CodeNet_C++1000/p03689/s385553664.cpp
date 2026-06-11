#include <iostream>
using namespace std;
int N, M, n, m;
int Matrix[505][505];
void fillMatrix()
{
    int sum = -4000;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            Matrix[i][j] = 4000, sum += 4000;
    Matrix[n][m] = -sum - 1;
    for(int j = m + 1; j <= M; j++)
    {
        for(int i = 1; i <= n; i++)
            Matrix[i][j] = Matrix[i][j - m];
    }
    for(int i = n + 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            Matrix[i][j] = Matrix[i - n][j];
    long long s = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            s += Matrix[i][j];
    if(s >= 0)
    {
        cout << "Yes\n";
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                cout << Matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    cout << "No\n";
}
int main()
{
    cin >> N >> M >> n >> m;
    fillMatrix();
    return 0;
}
