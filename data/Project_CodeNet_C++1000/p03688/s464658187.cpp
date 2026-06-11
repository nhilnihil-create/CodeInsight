#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mi=n,mx=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mi=min(mi,a[i]);
        mx=max(mx,a[i]);
    }
    if(mx-mi>1) cout<<"No\n";
    else {
        if(mx==mi)
        {
            if(mx==n-1) cout<<"Yes\n";
            else{
                int num=n/2;
                if(mx<=num) cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
        else{
            int cntmin=0,cntmx=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==mi) cntmin++;
                else cntmx++;
            }
            if(cntmx==1) cout<<"No\n";
            else{
                int kind=cntmin+cntmx/2;
                if(kind>=mx&&mx>=cntmin+1) cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }
}