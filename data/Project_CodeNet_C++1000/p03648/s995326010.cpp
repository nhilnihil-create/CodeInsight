#include <bits/stdc++.h>
 
//#define Saiyan
 
using namespace std;

template< class t>
long long int gcd( t g,t h )
{
    return ( h==0 ? g : gcd(h,g%h) );
}
 
int main()
{
    #ifdef Saiyan
  freopen("inp.txt","r",stdin) ;
  freopen("out.txt","w",stdout) ;
  #endif
 
  ios_base::sync_with_stdio(false) ; cin.tie(0) ;
 
  long long int t,i,j,a[100],k,temp;
  
  cin>>k;
  cout<<50<<endl;
  
  for(i=0;i<50;i++)
  {
      a[i]=i;
  }
  
  temp=k/50;
  
  for(i=0;i<50;i++)
  {
      a[i]+=temp;
  }
  
  temp=k%50;
  j=49;
  
  for(i=0;i<temp;i++)
  {
     a[j]++;
     j--;
  }
  
  for(i=0;i<50;i++)
  {
      cout<<a[i]<<" ";
  }
  
   return 0;
}