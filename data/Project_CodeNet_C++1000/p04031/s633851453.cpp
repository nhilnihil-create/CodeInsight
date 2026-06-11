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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;cin >> n;
    vector<int> a(n);rep(i,n)cin >> a[i];
    int i;
    int ans = 0;
    int mn = INF;
    for (i = -100; i <= 100; i++)
    {
        int diff = 0;
        for (int j = 0; j < n; j++)
        {
            diff += (abs(i - a[j]) * abs(i - a[j]));
        }
        if(diff < mn)
        {
            mn = diff;
            ans = diff;
        }
    }
    cout << ans << endl;
}