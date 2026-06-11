#include <bits/stdc++.h>
#define res register int
#define N 100005
using namespace std;
int n,ans,a[100100];
inline int read()
{
  int X=0,w=0;
  char ch=0;
  while(!isdigit(ch))
  {
    w|=ch=='-';
    ch=getchar();
  }
  while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
  return w?-X:X;
}
inline bool cmp(int x,int y)
{
  return x>y;
}
int main()
{
  n=read();
  for(res i=1; i<=n; i++)
    a[i]=read();
  sort(a+1,a+n+1,cmp);
  for(res i=1; i<=n; i++)
    if(i+1>a[i+1])
    {
      for(res j=i+1; a[j]==i; j++) ans^=1;
      ans|=(a[i]-i)&1;
      puts(ans? "First":"Second");
      return 0;
    }
  return 0;
}