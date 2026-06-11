#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
vector<string> a;
vector<string> b;
int n, m;
bool judge(int x,int y)
{
    bool ret = true;
    rep(i,m)
    {
        rep(j,m)
        {
            if(b[i][j]!=a[i+x][j+y])
            {
                ret = false;
            }
        }
    }
    return ret;
}
int main()
{
    cin >> n >>m;
    a.resize(n);rep(i,n)cin >> a[i];
    b.resize(m);rep(i,m)cin >> b[i];
    
    for (int dx = 0; dx+m-1 <= n-1; dx++)
    {
        for (int dy = 0; dy + m - 1 <= n - 1; dy++)
        {
            if(judge(dx,dy))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
}