#include<bits/stdc++.h>

using namespace std;

int sec[200010];
int n;

bool check(int x)
{
    for(int i=0;i<n;i++)
    {
        if((sec[n+i]<=x&&sec[n+i+1]<=x)||(sec[n-i]<=x&&sec[n-i-1]<=x)) return 1;
        if((sec[n+i]>x&&sec[n+i+1]>x)||(sec[n-i]>x&&sec[n-i-1]>x)) return 0;
    }
    return sec[1]<=x;
}

int main()
{
    cin>>n;
    for(int i=1;i<=2*n-1;i++)
    {
        cin>>sec[i];
    }
    int l=1,r=2*n-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l<<'\n';
}