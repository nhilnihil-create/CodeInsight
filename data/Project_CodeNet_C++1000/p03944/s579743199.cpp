#include<bits/stdc++.h>
using namespace std;
int main()
{
   int x,y,n,w,h,p,c1=0,c2=0;
   cin>>x>>y>>n;
   int a[x],b[y],i;
   for(i=0;i<x;i++) a[i]=0;
   for(i=0;i<y;i++) b[i]=0;
   while(n--)
   {
       cin>>w>>h>>p;
       if(p==1) for(i=0;i<w;i++) a[i]=1;
       else if(p==2) for(i=w;i<x;i++) a[i]=1;
       else if(p==3) for(i=0;i<h;i++) b[i]=1;
       else if(p==4) for(i=h;i<y;i++) b[i]=1;
   }


   for(i=0;i<x;i++)
   {
       if(a[i]==0) c1++;
   }
   for(i=0;i<y;i++)
   {
       if(b[i]==0) c2++;
   }
   cout<<c1*c2<<endl;
    return 0;
}






