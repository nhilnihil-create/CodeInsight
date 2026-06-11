#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,n) for(int i=0 ; i < (int) (n) ; ++i )

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    int ans=1000;
    rep(i,n)
    {
        // 最初はどこになるか
        bool flag = true;
        for (int j=0;j<n-i;j++)
        {
            if (s[i+j]!=t[j]) flag = false;
        }
        if (flag)
        {
            ans = min(ans, n + i);
        }
    }
    cout << min(ans, 2 * n) << endl;
}


