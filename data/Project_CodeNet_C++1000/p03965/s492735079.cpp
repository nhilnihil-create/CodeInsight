#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e9+7;
int a[2];
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    string s;cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='p')a[1]++;
        else a[0]++;
    }
    cout<<floor((a[0]-a[1])/2);
    return 0;
}
