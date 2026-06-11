#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    a += b;
    for(auto c : s)
    {
        string ans = "No";
        if(c=='a')
        {
            if(a != 0)
            {
                ans = "Yes";
                a--;
            }
        }
        else if(c=='b')
        {
            if(a != 0 && b != 0)
            {
                ans = "Yes";
                b--;
                a--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
