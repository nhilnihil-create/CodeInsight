#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans=0, sum=0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i]=='I') sum++;
        else ans=max(ans, sum), sum--;
    }
    ans=max(ans, sum);
    cout << ans;
}
