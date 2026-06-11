#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 105;
int n, m, k, col[N * N], a[N][N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
        cin >> col[i];
    int idx = 1;
    for(int i = 0; i < n; i++){
        if(i % 2){
            for(int j = m - 1; j > -1; j--){
                if(col[idx])
                    a[i][j] = idx, col[idx]--;
                else{
                    idx++;
                    j++;
                }
            }
        }
        else{
            for(int j = 0; j < m; j++){
                if(col[idx])
                    a[i][j] = idx, col[idx]--;
                else
                    idx++, j--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
