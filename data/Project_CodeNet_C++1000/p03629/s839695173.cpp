#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
const int inf=1e9+10;
const ll llinf=1e16+10;
const int maxn=2e5+10;
const int maxm=1e3+10;
const int mod=1e9+7;
int n;
vector<int> v[30];
char s[maxn];
int dp[maxn];
int nch=26;
int querry(int pos,int ch)
{
    vector<int>::iterator it;
    it=lower_bound(v[ch].begin(),v[ch].end(),pos);
    if(it==v[ch].end()) return n;
    else return *it;
}
void solve()
{
    dp[n+1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<nch;j++)
            dp[i]=min(dp[i],dp[querry(i,j)+1]+1);
    }
    int pos=0;
    while(pos<n)
    {
        for(int j=0;j<nch;j++)
        {
            int t=querry(pos,j)+1;
            if(dp[pos]==dp[t]+1)
            {
                printf("%c",j+'a');
                pos=t;
                break;
            }
        }
    }
    printf("\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
       cin>>s;
    
        for(int i=0;i<nch;i++)
            v[i].clear();
        n=strlen(s);
        for(int i=0;i<=n;i++)
            dp[i]=inf;
        for(int i=0;i<n;i++)
            v[s[i]-'a'].pb(i);
        solve();
    
    return 0;
}