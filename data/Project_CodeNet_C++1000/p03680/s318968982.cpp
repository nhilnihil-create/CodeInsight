#include <bits/stdc++.h>
using namespace std;

int a[100050];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)cin>>a[i];
    
    int c=1;
    int cnt=0;
    
    for(int i=0;i<n;i++)
    {
        if(c==a[c-1])
        {
            c=1;
            break;
        }
        c=a[c-1];
        cnt++;
        if(c==1)break;
        if(c==2)break;
    }
    
    if(c==1||cnt==n)cout<<-1;
    else cout<<cnt;
    cout<<"\n";

    return 0;
}

