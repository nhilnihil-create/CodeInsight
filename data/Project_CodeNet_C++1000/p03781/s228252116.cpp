#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{  ll n,m=0,i,la=0;

   cin>>n;
  for(i=1;i<pow(10,9);i++)
 { m=m+i;la++;
    if(m>=n)break;

 }
  cout<<la<<endl;



}
