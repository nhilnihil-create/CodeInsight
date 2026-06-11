#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int a,b,c,d,e=10000000000000,i,k,j,l=0;
 vector<long long>v;
  cin>>a;
  for(i=1;i<=a;i++)
  {
  cin>>b;
  v.push_back(b);l+=b;
  }
  
  for(i=0;i<a-1;i++)
  {
    j+=v[i];
   k=l-j;
   e=min(e,abs(k-j));
  //cout<<e<<endl;
 
  }
cout<<e<<endl;
}