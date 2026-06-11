#include <bits/stdc++.h>
using namespace std;
long long A[3];
int main()
{
long long a,b,i,c=0,d=0,n,m,t,j;
cin>>n;
for(i=0;i<n;i++)
{
  cin>>a>>b;
  c+=(b-a+1);
}
std::cout <<c<< '\n';
return 0;
}
