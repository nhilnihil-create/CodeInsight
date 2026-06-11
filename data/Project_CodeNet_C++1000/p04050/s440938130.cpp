#include <bits/stdc++.h>
using namespace std;
const int N=5e5;

#define C getchar()-48
int read()
{
  int s=0,t=1,k=C;
  for (;k<0||9<k;k=C) if (k==-3) t=-1;
  for (;0<=k&&k<=9;k=C) s=(s<<1)+(s<<3)+k;
  return s*t;
}

  int n,t;
  int a[N];
void in()
{
  cin>>n>>n;
  for (int i=0;++i<=n;)
    t+=1&(a[i]=read());
}

void GG()
{
  puts("Impossible");
}

void w1()
{
  cout<<a[1]<<endl;
  a[2]=a[1]/2+1;
  if (a[2]^a[1])
	  ++n,a[1]-=a[2];
  cout<<n<<endl;
  for (int i=0;++i<=n;)
    cout<<a[i]<<' ';
}

void w2(int f=0)
{
  for (int i=0;++i<=n;)
    if (a[i]&1)
      swap(a[i],a[(n-f)%n+1]),
			f^=1;
  for (int i=0;++i<=n;)
    printf("%d ",a[i]);
  puts("");
  ++a[1],--a[n]; 
  if (!a[n]) --n;
  cout<<n<<endl;
  for (int i=0;++i<=n;)
    printf("%d ",a[i]);
}

void sol()
{
  if (t>2) GG();
  else
	if (n==1) w1();
  else
	w2();
}

int main()
{
  in();
  sol();
  exit(0);
}