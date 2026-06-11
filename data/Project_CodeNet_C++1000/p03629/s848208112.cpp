#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[200005];
int nxt[200005][26];
int pos[26];

signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    string a;
    cin>>a;
    int n=a.length();
    a="#"+a;
    fill_n(pos,26,n+1);

    for(int i=0;i<26;i++)
        nxt[n+1][i]=n+1;

    for(int i=n;i>=1;i--)
    {
        pos[a[i]-'a']=min(pos[a[i]-'a'],i);
        for(int j=0;j<26;j++)
            nxt[i][j]=pos[j];
    }

    dp[n+1]=1;
    for(int i=n;i>=1;i--)
    {
        int mn=1e9;
        for(int j=0;j<26;j++)
        {
            mn=min(mn,dp[nxt[i][j]+1]);
        }
        dp[i]=mn+1;
    }
    int len=dp[1];
    int ini=1;
    string ans="";
    while(ini<=n)
    {
        for(int j=0;j<26;j++)
        {
            if(nxt[ini][j]==n+1)
            {
                ans+=char(j+97);
                cout<<ans;
                return 0;
            }
            if(dp[nxt[ini][j]+1]==len-1)
            {
                ini=nxt[ini][j]+1;
                ans+=char(j+97);
                break;
            }
        }
        len--;
    }
    cout<<ans;

} 

