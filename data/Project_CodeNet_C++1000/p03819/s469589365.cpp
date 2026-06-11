#include<bits/stdc++.h>
#define int long long
using namespace std;
 

int seg[400005];

void upd(int ver,int tl,int tr,int l,int r,int val)
{
    if(tl>tr||l>r||tr<l||r<tl)
        return ;
    else if(tl==l&&tr==r)
    {
        seg[ver]+=val;
    }
    else
    {
        int tm=(tl+tr)/2;
        upd(2*ver,tl,tm,l,min(tm,r),val);
        upd(2*ver+1,tm+1,tr,max(tm+1,l),r,val);
    }    
}

int get(int ver,int tl,int tr,int pos)
{
    if(tl>tr)
        return 0;
    else if(tl==tr)
    {
        return seg[ver];
    }
    else
    {
        int tm=(tl+tr)/2;
        if(tm>=pos)
            return seg[ver]+get(2*ver,tl,tm,pos);
        else
            return seg[ver]+get(2*ver+1,tm+1,tr,pos);
    }    
}


signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > >pp;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        pp.push_back({y-x+1,{x,y}});
    }
    sort(pp.begin(),pp.end());
    int ini=0;
    int tot=n;
    
    for(int i=1;i<=m;i++)
    {
        if(ini<n)
        while (ini<n && i>=pp[ini].first)
        {
            upd(1,1,m,pp[ini].second.first,pp[ini].second.second,1);
            ini++;
            tot--;
        }

        int ans=0;
        for(int j=i;j<=m;j+=i)
        {
            ans+=get(1,1,m,j);
        }
        cout<<tot+ans<<'\n';
    }

}