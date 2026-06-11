#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    const ll mod=1000000007;
    auto add=[&](ll &a,ll b){a=(a+b)%mod;};
    vector<vector<ll>> one(n+1,vector<ll>(n+1,0));
    one[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            add(one[i+1][j+1],2*one[i][j]);
            add(one[i+1][max(0,j-1)],one[i][j]);
        }
    }
    ll res=one[n][s.size()];
    for(int i=0;i<(int)s.size();i++) res=(res*(mod+1)/2)%mod;
    cout << res << "\n";
    return 0;
}
