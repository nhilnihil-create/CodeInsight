#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1e9 + 7;
int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= H; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(i % h == 0 && j % w == 0) cout << -(h*w-1) * 1000 -1 << " ";
            else cout << "1000 ";
        }
        cout << endl;
    }
}
