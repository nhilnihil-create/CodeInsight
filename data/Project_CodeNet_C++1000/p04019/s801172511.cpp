#include<bits/stdc++.h>
using namespace std;

int main()
{
   string a;
   cin>>a;
   int n =0, s=0 , w=0, e=0;
   for( int  i=0;i<a.length();i++)
   {
       if( a[i] == 'N')
           n++;
       if( a[i] == 'S')
           s++;
       if( a[i] == 'W')
           w++;
       if( a[i] == 'E')
           e++;

   }
   int hmin   = min( w,e);
   int hmax = max( w,e);
   int vmin = min(n,s);
   int vmax = max( n,s);
   if( hmin == 0 && hmax!=0 )
   {
       cout<<"No";

   }
   else if( vmin==0 && vmax != 0 )
   {
       cout<<"No";
   }
   else cout<<"Yes";



}