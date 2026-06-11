#include <iostream>
  using namespace std;
 long long  a[51000000];
 long long  n,a1,b1;
 long  panduan(long long  x)
 {
     long long  t=b1*x;
     long long  add=0;
     for(int i=1;i<=n;i++)
     {
         if(a[i]-t>0)
         {
             if((a[i]-t)%(a1-b1)==0)
                 add+=(a[i]-t)/(a1-b1);
             else
                 add+=(a[i]-t)/(a1-b1)+1;
         }
     }
     return add<=x;
 }
 int  main()
 {
     cin>>n>>a1>>b1;
     for(int i=1;i<=n;i++)
        cin>>a[i];
     long long  y=0,z=1e10;
     long long  mid;
     int t;
     while(y<z-1)
     {
         mid=(y+z)/2;
         if(panduan(mid))
         {
             z=mid;
             t=mid;
         }
         else
             y=mid;
     }
     cout<<z<<endl;
     return 0;
 }
