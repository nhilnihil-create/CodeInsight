#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define PI 3.14159265359
static const int INF = 1e9+7;
typedef long long ll;
using namespace std;
int main()
{

    string s;
    cin>>s;
    string ans;
    int n=s.length();
    rep(i,s.size())
    {
        if(s[i] == 'B' && ans.size()>0) ans.erase(ans.end()-1,ans.end());
        else if(s[i] != 'B') ans += s[i];
    }

    cout << ans << endl;
    return 0;
}
