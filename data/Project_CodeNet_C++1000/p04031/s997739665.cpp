#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
  int n,i,j,min=1000000000,cost;
  cin>>n;
  int list[n];
   for(i=0;i<n;i++)
     cin>>list[i];
  sort(list,list+n);
  for(i=list[0];i<=list[n-1];i++)
  {   
      cost=0;
     for(j=0;j<n;j++)
     {
       cost+=pow(i-list[j],2);
     }
    if(cost<min)
       min=cost;
  }
  cout<<min;
  return 0;
}
  
  