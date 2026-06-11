#include<bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) cout << #x << "--> " << x << endl;
#define int long long
#define pii pair<int, int>
using namespace std;
main()
{
    fastio;
    int n; cin >> n;
    map<int, int>mp;
    vector<int>vec;
    for(int i = 0; i < n; i++)
    {
         int x; cin >> x;
         if(mp[x] == false) vec.push_back(x);
            mp[x]++;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int ans = 0;
    int a = 0, b = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        if(mp[vec[i]] >= 4) ans = max(ans, vec[i] * vec[i]);
        if(mp[vec[i]] >= 2)
        {
            if(!a) a = vec[i];
            else if(!b) b = vec[i];
        }
        ans = max(ans, a * b);
    }
    cout << ans << endl;
}
