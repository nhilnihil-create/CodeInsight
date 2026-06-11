#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    bool flag[4];
    rep(i,4) flag[i] = false;
    string s;
    cin >> s;
    rep(i,s.length())
    {
        if (s[i]=='S')
        {
            flag[0] = true;
        }
        else if (s[i]=='N')
        {
            flag[1] = true;
        }
        else if (s[i]=='W')
        {
            flag[2] = true;
        }
        else
        {
            flag[3] = true;
        }
    }

    bool ans = false;
    if (flag[0] && flag[1] && flag[2] && flag[3])
    {
        ans = true;
    }
    else if (flag[0] && flag[1] && !flag[2] && !flag[3])
    {
        ans = true;
    }
    else if (!flag[0] && !flag[1] && flag[2] && flag[3])
    {
        ans = true;
    }

    if(ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}
