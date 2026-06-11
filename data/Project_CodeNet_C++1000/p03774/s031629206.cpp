#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
using LP = pair<ll,ll>;
using P = pair<ll,int>;
ll inf = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<LP> x(n), y(m);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        x[i] = LP(a,b);
    }
    rep(i, m){
        int c, d;
        cin >> c >> d;
        y[i] = LP(c,d);
    }
    rep(i, n){
        P ans (inf, 0);
        rep(j, m){
            ll tmp = abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second);
            ans = min(ans, P(tmp, j));
        }
        cout << ans.second+1 << endl;
    }

}