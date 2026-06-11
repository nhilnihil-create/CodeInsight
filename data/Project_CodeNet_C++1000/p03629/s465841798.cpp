#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    vector<int> dp(n,n+2);
    vector<char> p(n,'0');
    auto best=[&](int i,int len,char to)
    {
        if(len<dp[i]||(len==dp[i]&&to<p[i]))
        {
            dp[i]=len;
            p[i]=to;
        }
    };
    vector<int> nxt(26,-1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
        {
            if(nxt[j]==-1) best(i,1,j+'a');
            else best(i,dp[nxt[j]]+1,j+'a');
        }
        nxt[s[i]-'a']=i;
    }
    for(int i=0;i<26;i++)
    {
        if(nxt[i]==-1)
        {
            cout << (char)(i+'a') << "\n";
            return 0;
        }
    }
    int src=0;
    for(int i=0;i<n;i++)
    {
        if(nxt[s[i]-'a']==i&&(dp[i]<dp[src]||(dp[i]==dp[src]&&s[i]<s[src]))) src=i;
    }
    cout << s[src];
    int idx=src;
    while(1)
    {
        char now=p[idx];
        cout << now;
        idx++;
        while(idx<n&&s[idx]!=now) idx++;
        if(idx==n) break;
    }
    cout << "\n";
    return 0;
}
