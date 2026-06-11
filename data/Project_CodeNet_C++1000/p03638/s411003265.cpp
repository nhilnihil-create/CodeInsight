#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w, n, k = 0;
    cin >> h >> w >> n;
    int arr[n], ans[h][w];
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    bool shuf = 1;
    for(int i = 0;i < h;++i)
    {
        if(shuf)
        {
            for(int j = 0;j < w;++j)
            {
                k += (!arr[k]);
                ans[i][j] = k + 1;
                --arr[k];
            }
        }
        else
        {
            for(int j = w - 1;j >= 0;--j)
            {
                k += (!arr[k]);
                ans[i][j] = k + 1;
                --arr[k];
            }
        }
        shuf = !shuf;
    }
    for(int i = 0;i < h;++i)
    {
        for(int j = 0;j < w;++j)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
