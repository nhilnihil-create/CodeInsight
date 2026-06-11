#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;pair<int,int> st[n],ch[m];
    for(int i=0;i<n;i++){cin>>st[i].first>>st[i].second;}
    for(int i=0;i<m;i++){cin>>ch[i].first>>ch[i].second;}
    ///-----------------------------------------------///
    for(int i=0;i<n;i++)
    {
        long long pos,mn=1e12;
        for(int j=0;j<m;j++)
        {
            if(abs(st[i].first-ch[j].first)+abs(st[i].second-ch[j].second)<mn)
            {
                pos=j+1;
                mn=abs(st[i].first-ch[j].first)+abs(st[i].second-ch[j].second);
            }
        }
        cout<<pos<<endl;
    }
}
