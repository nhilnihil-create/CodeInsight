#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    int h, w, n, idx = 1;
    cin >> h >> w >> n;
    int arr[n + 5], ans[h + 5][w + 5];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i < h; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < w; j++)
            {
                if(arr[idx])
                    ans[i][j] = idx;
                else
                {
                    while(!arr[idx])
                        idx++;
                    ans[i][j] = idx;
                }
                arr[idx]--;
            }
        }
        else
        {
            for(int j = w - 1; j >= 0; j--)
            {
                if(arr[idx])
                    ans[i][j] = idx;
                else
                {
                    while(!arr[idx])
                        idx++;
                    ans[i][j] = idx;
                }
                arr[idx]--;
            }
        }
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
