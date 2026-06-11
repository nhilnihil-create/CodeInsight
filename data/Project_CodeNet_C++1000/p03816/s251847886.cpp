#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=1e5+3;
int c[N];
int main()
{
    ft
    int t,i,j,n,m,l=0,r=0,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        c[m]++;
    }
    for(i=1;i<N;i++)
    {
        if(c[i]>0)
        {
            if(c[i]%2==1)
            {
                l++;
            }
            else
            {
                r++;
            }
        }
    }
    if(r%2==0)
    {
        cout<<(l+r)<<"\n";
    }
    else
    {
        cout<<(l+r-1)<<"\n";
    }
    return 0;
}

