#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int H, W;
int N;
int arr[MAXN];
int res[110][110];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> H >> W >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int cloc = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            int cj = j;
            if (i % 2) cj = (W - 1 - j);
            res[i][cj] = cloc;
            arr[cloc]--;
            if (!arr[cloc]) cloc++;
        }

    for (int i = 0; i < H; i++)
    {
        for (int j =0 ; j < W; j++)
            cout << res[i][j] + 1 << " ";
        cout << "\n";
    }
}