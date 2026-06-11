#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {1, 0}, dy = {1, 0};
//cin.tie(0);
//ios::sync_with_stdio(false);

void solve(vector<int> &v)
{
    rep(i, siz(v))
    {
        if (v[i] == 0)
        {
            cout << 'S';
        }
        else
        {
            cout << 'W';
        }
    }
    cout << endl;
    return;
}

signed main()
{
    int n;
    string s;
    cin >> n >> s;

    for (int j = 0; j < 4; j++)
    {
        vector<int> u(n,0);
        u[0] = j % 2;
        u[1] = j / 2;

        for (int i = 1; i < n; i++)
        {
            if ((s.at(i) == 'o' && u[i] == 0) || (s[i] == 'x' && u[i] == 1))
            {
                if(i==n-1 && u[0]!=u[n-2]){
                    goto flag;
                }
                u.at((i+1)%n) = u[i - 1];
            }
            else
            {
                if(i==n-1 && u[0]!=1-u[n-2]){
                    goto flag;
                }
                u.at((i+1)%n) = (1 - u[i - 1]);
            }
        }

        if(u[1]==u[n-1] && ((s[0]=='o'&&u[0]==0) || (s[0]=='x'&&u[0]==1))){
            solve(u);
            return 0;
        }else if(u[1]!=u[n-1] && ((s[0]=='o'&&u[0]==1) || (s[0]=='x'&&u[0]==0))){
            solve(u);
            return 0;
        }
        flag:;
    }

    cout << -1 << endl;
}