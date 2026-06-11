#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
    int n,k,a[100],i,j,l,r,q,d,c=0,f=0,fo=0,found=0;
    map<int,int>p;
    vector<int>v;
    vector<int>x;
    cin>>n>>k;q=n;
    for(i=0;i<k;i++){
        cin>>a[i];
        p[a[i]]=1;}
    while(q!=0)
    {
        c++;
        r=q%10;
        v.pb(r);
        q=q/10;
    }j=v.size()-1;d=c;
    while(p[v[j]]==0&&j>=0)
    { x.pb(v[j]);found=1;
    j--;
    }
    if(j>=0){
    for(i=v[j]+1;i<=9;i++)
    {
        if(p[i]==0)
        {
            x.pb(i);f=1;
            break;
        }
    }
    if(f==0)
    {
        if(found==1)
            x.clear();
        for(i=1;i<v[j];i++)
        {
            if(p[i]==0)
            {
            x.pb(i);fo=1;
            break;
            }
        }
    }
    for(i=0;i<=9;i++)
    {
        if(p[i]==0)
        {
            l=i;break;
        }
    }
    for(i=0;i<x.size();i++)
        cout<<x[i];
    if(f==1)
    {
        d=d-x.size();
       while(d--)
            cout<<l;
    }
    if(fo==1)
    {
        while(d--)
            cout<<l;
    }
    }
    if(found==1&&f==0&&fo==0)
    {
        for(i=0;i<x.size();i++)
        cout<<x[i];
    }
}
