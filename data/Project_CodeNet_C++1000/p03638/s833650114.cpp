#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int h,w,n,i,j;
    cin>>h>>w;
    cin>>n;
    int a[n];
    for (i=0;i<n;i++)
        cin>>a[i];
    int ans[h][w],ctr=0;
    for (i=0;i<h;i++)
    {
        if (i%2==0)
        {
            for (j=0;j<w;j++)
            {
                if (a[ctr])
                {
                    ans[i][j]=ctr+1;
                    a[ctr]--;
                }
                else
                {
                    ctr++;
                    ans[i][j]=ctr+1;
                    a[ctr]--;
                }
            }
        }
        else
        {
            for (j=w-1;j>=0;j--)
            {
                if (a[ctr])
                {
                    ans[i][j]=ctr+1;
                    a[ctr]--;
                }
                else
                {
                    ctr++;
                    ans[i][j]=ctr+1;
                    a[ctr]--;
                }
            }
        }
    }
    for (i=0;i<h;i++)
    {
        for (j=0;j<w;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}