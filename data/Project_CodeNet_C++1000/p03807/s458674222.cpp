#include<bits/stdc++.h>
using namespace std;

int main()

{
   long long a=0,b=0,c,d,e,f,g,h,i,j,k,l,m,n,t;

   cin>>n; long long ar[n];

   for(i=0;i<n;i++)
   {
       cin>>ar[i];

       if(ar[i]%2==1) a++;
   }

   if(a%2==0) cout<<"YES"<<endl;

   else if(a%2==1) cout<<"NO"<<endl;
}
