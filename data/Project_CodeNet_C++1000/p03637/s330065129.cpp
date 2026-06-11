#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int cnt=0,two=0;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    if(x%4==0)cnt++;
    if(x%2==0 && x%4!=0)two++;
  }
  two--;
  if(two>0)n-=two;
  if(cnt>=n/2)puts("Yes");
  else puts("No");
}
