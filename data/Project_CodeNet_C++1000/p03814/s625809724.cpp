#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, ans=0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]=='A')
        {
            int k=i;
            for(int j = s.size()-1; j > i; j--)
            {
                if(s[j]=='Z')
                {
                    ans=max(ans, j-k+1);
                    break;
                }
            }
            break;
        }
    }
    cout << ans;
}
