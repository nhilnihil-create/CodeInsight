#include <bits/stdc++.h>
using namespace std;
const int N=5e5;

  int n;
  int a[N];
int cmp(int x,int y)
{
  return x>y;
} 
 
int main()
{
  cin>>n;
  for (int i=n;i;--i)
    scanf("%d",a+i);
  sort(a+1,a+n+1,cmp);
  int z=1;
  while (z<n&&a[z+1]>z) ++z;
  int x=a[z],y=z;
  while (a[y+1]>=z) ++y;
  if ((x-z&1)|(y-z&1))
    puts("First");
  else
    puts("Second");
  exit(0);
} 