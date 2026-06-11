#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=1000;
const int px=2000;
const ll INF=1LL << 50;
int main()
{
   int n,m;
   cin>>n>>m;
   int a[px],b[px];
   ll c[px];
   for(int i=0;i<m;i++)
   {
       cin>>a[i]>>b[i]>>c[i];
       c[i]=-c[i];
   }
   ll d[mx];
   for(int i=0;i<n;i++)
   {
       d[i]=INF;
   }
   d[0]=0;
   for(int l=0;l<n-1;l++)
   {
       for(int i=0;i<m;i++)
       {
           if(d[a[i]-1]==INF) continue;
           if(d[b[i]-1]>d[a[i]-1]+c[i])
           {
               d[b[i]-1]=d[a[i]-1]+c[i];
           }
       }
   }
   ll ans=d[n-1];
   bool ma[mx];
   for(int i=0;i<n;i++)
   {
       ma[i]=false;
   }
   for(int l=0;l<n;l++)
   {
       for(int i=0;i<m;i++)
       {
           if(d[a[i]-1]==INF) continue;
           if(d[b[i]-1]>d[a[i]-1]+c[i])
           {
               d[b[i]-1]=d[a[i]-1]+c[i];
               ma[b[i]-1]=true;
           }
           if(ma[a[i]-1]==true)
           {
               ma[b[i]-1]=true;
           }
       }
   }
   if(ma[n-1])
    cout<<"inf"<<endl;
   else
    cout<<-ans<<endl;
}
