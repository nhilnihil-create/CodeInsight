#include <bits/stdc++.h>
using namespace std;
const int N=233;

void GG()
{
  puts("Impossible");
  exit(0);
}

  int n,l=100,m,x;
  int v[N];
int main()
{
  cin>>n;
  for (int i=0;++i<=n;)
    cin>>x,++v[x];
  while (!v[l]) --l;
  m=l+1>>1;
  if (l==1&&n>2) GG();
  if (!(l&1)&&(v[m]^1)&&n>2) GG();
  if ((l&1)&&(v[m]^2)&&n>1) GG();
  for (int i=m;++i<=l;)
    if (v[i]<2) GG();
  for (int i=0;++i<m;)
    if (v[i]) GG();
  puts("Possible");
  exit(0);
}