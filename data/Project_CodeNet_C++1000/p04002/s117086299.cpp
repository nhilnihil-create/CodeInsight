#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Bound = 1e9 + 10;

unordered_map<ll , int> mp;
#define cnv(x , y) (ll(x) * Bound + ll(y))

int res[10];
int main()
{
    int h , w , n;cin >> h >> w >> n;
    for(int i = 0;i < n ;i++)
    {
        int a , b;cin >> a >> b;
        for(int j = 0;j < 3;j++)
        {
            if(j >= a)
                break;
            for(int k = 0;k < 3;k++)
            {
                if(k >= b)
                    break;
                if(a - j <= h - 2 && b - k <= w - 2)
                    mp[cnv(a - j , b - k)]++;
            }
        }
    }
    int num = 0;
    for(auto v : mp)
    {
        num++;
        res[v.second]++;
    }
    cout << ll(h - 2) * ll(w - 2) - num << "\n";
    for(int i = 1;i < 10;i++)
        cout << res[i] << "\n";
}

