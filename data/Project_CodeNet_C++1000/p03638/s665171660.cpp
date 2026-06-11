#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int h,w,n,hh=0,ww=0,nn=1,now=0;
    cin>>h>>w>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    vector<vector<int>> ans(h,vector<int>(w));
    rep(i,h*w)
    {
        ans[hh][ww]=nn;
        a[nn-1]--;
        if(now==0)
        {
            if(ww+1==w)
            {
                hh++;
                now++;
            }
            else ww++;
        }
        else
        {
            if(ww==0)
            {
                hh++;
                now--;
            }
            else ww--;
        }
        if(a[nn-1]==0) nn++;
    }
    rep(i,h)
    {
        rep(j,w) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
