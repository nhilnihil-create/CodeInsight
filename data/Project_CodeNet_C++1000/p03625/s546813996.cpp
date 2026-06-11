#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int>a(n);
    for(i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int64_t area=1,x=-1,y=-1;
    int c=0;
    for(i=0;i<n-1;i++)
    {
        if(c==2)break;
        if(a[i]==a[i+1])
        {
            c++;
            area*=a[i];
            i++;
        }
    }
    if(c<2)cout<<0<<endl;
    else cout<<area<<endl;
}
