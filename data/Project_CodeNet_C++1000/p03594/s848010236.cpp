#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,type;
int read()
{
  char c=0;
  int sum=0;
  while (c<'0'||c>'9')
    c=getchar();
  while ('0'<=c&&c<='9')
    {
      sum=sum*10+c-'0';
      c=getchar();
    }
  return sum;
}
int main()
{
  n=read(),m=read(),k=read();
  for (int i=1;i<=n;++i)
    {
      for (int j=1;j<=m;++j)
	{
	  type=(((i+j-2)/k)&1)*2+(((i-j+m)/k)&1);
	  if (type==0) printf("R");
	  if (type==1) printf("Y");
	  if (type==2) printf("G");
	  if (type==3) printf("B");
	}
      puts("");
    }
  return 0;
}