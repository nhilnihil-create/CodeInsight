#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mpp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 1e5 + 5;
int mp[6][6] , sum[6][6];
ll cnt[15];
map<pair<int,int> , bool> Q;
int ask (int x , int y , int a , int b)
{
    return sum[a][b] - sum[x - 1][b] - sum[a][y - 1] + sum[x - 1][y - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    ll n , m , q; cin >> n >> m >> q;
    cnt[0] = (n - 2) * (m - 2);
    while (q--){
        int a , b; cin >> a >> b;
        for (int i = a - 2 ; i <= a + 2 ; i++){
            for (int j = b - 2 ; j <= b + 2 ; j++){
                int x = i - (a - 2) + 1 , y = j - (b - 2) + 1;
                if (i <= 0 || i > n || j <= 0 || j > m)
                    mp[x][y] = -1e5;
                else
                    mp[x][y] = Q[mpp(i , j)];
                sum[x][y] = sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1] + mp[x][y];
            }
        }
        for (int i = a ; i <= a + 2 ; i++){
            for (int j = b ; j <= b + 2 ; j++){
                int x = i - (a - 2) + 1 , y = j - (b - 2) + 1;
                if (i <= 0 || i > n || j <= 0 || j > m) continue;
                int res = ask(x - 2 , y - 2 , x , y);
                if (res < 0) continue;
                cnt[res]--;
                cnt[res + 1]++;
            }
        }
        Q[mpp(a , b)] = 1;
    }
    for (int i = 0 ; i <= 9 ; i++) cout << cnt[i] << endl;
    return 0;
}
