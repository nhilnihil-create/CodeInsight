#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,k;
    cin>>n>>k;
    int d[10]={0};
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        d[x]=1;
    }
    for(int i=n;i<=100000;i++)
    {
        string s=to_string(i);
        int cnt=0;
        for(int j=0;j<s.size();j++)
        {
            if(d[s[j]-'0']==1)
                break;
            cnt++;
        }
        if(cnt==s.size())
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
