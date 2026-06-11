#include<bits/stdc++.h>
using namespace std;
int dp[1000000];
int main()
{
    string str;
    cin>>str;
    dp[0]=1;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(dp[i]==0)continue;
        if(i+5<=n && str.substr(i,5)=="dream")dp[i+5]=1;
        if(i+7<=n && str.substr(i,7)=="dreamer")dp[i+7]=1;
        if(i+5<=n && str.substr(i,5)=="erase")dp[i+5]=1;
        if(i+6<=n && str.substr(i,6)=="eraser")dp[i+6]=1;
    }
    if(dp[n]==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
