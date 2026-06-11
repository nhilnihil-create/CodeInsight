
#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
int Next[maxn][30], now[30], now_tot[maxn];
char s[maxn];
set<int>S;
vector<int>ans;
int main()
{
    ios::sync_with_stdio(false);
cin >> s+1;
        ans.clear();
        int len = strlen(s+1);
        int tot = 0;

        S.clear();
        for(int i = len; i >= 1; i--)
        {
            now_tot[i] = tot;
            S.insert(s[i]-'a');
            if(S.size() == 26)
            {
                tot++;
                S.clear();
            }
        }
        if(tot == 0)
        {
            for(int i = 0; i < 26; i++)
            {
                if(S.count(i) == 0)
                {
                    ans.push_back(i+'a');
                    break;
                }
            }
        }
        else
        {
            for(int i = len; i>= 1; i--)
            {
                for(int  j = 0; j < 26; j++)
                {
                    Next[i][j] = now[j];
                }
                now[s[i]-'a'] = i;
            }
            int tmp = 0;
            for(int i = 0; i < 26; i++)
            {
                if(S.count(i) == 0)
                {
                    tmp = now[i];
                    ans.push_back(s[tmp]);
                    break;
                }
            }
            for(int i = 1; i < tot; i++)
            {
                for(int j = 0; j < 26; j++)
                {
                    if(now_tot[Next[tmp][j]] == now_tot[tmp]-1)
                    {
                        tmp = Next[tmp][j];
                        ans.push_back(s[tmp]);
                        break;
                    }
                }
            }
            for(int i = 0; i < 26; i++)
            {
                if(Next[tmp][i] == 0)
                {
                    ans.push_back(i+'a');
                    break;
                }
            }
        }
        for(int i = 0; i < ans.size(); i++)
        {
            cout << char(ans[i]);
        }
        cout << endl;
    return 0;
}
