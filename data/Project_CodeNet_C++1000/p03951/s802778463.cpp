#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    string ans = t;
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        for(int j = 0; j < n; j++)
        {
            if(ans[j] != s[j]) flag = false;
        }
        if(flag)
        {
            cout << ans.size() << endl;
            return 0;
        }
        ans = s.substr(0, i+1) + t;
    }
    cout << ans.size() << endl;
}
