#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
int n;
string ss;
vector<int> now;
ll ans;
void dfs(int cur)
{
    if(cur==n-1)
    {
        now.push_back(n-1);
        ll pre=0; int last=-1;
        for(int i=0;i<(int)now.size();i++)
        {
            for(int pos=last+1;pos<=now[i];pos++)
                pre=pre*(ll)10+(ll)(ss[pos]-'0');
            last=now[i]; ans+=pre; pre=0;
        }
        now.pop_back();
        return;
    }
    dfs(cur+1);
    now.push_back(cur);
    dfs(cur+1);
    now.pop_back();
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>ss;
    n=(int)ss.length();
    dfs(0);
    cout<<ans<<'\n';
    return 0;
}
