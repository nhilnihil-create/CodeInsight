#include<bits/stdc++.h>

#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;
#define ll long long
const int maxn=100000+10;
int x[maxn],xx[maxn],w[maxn];
int i,j,k,l,r,s,t,n,m;
ll c;

int read() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}
int main()
{
    n=read(),l=read(),t=read();
    fo(i,1,n)
        x[i]=read(),w[i]=read();
    fo(i,1,n)
    {
        if (w[i]==2) w[i]=-1;
        r=x[i]+w[i]*t;
        if (r>0) (c+=r/l)%=n;
        else if (r<0) (c+=(r+1)/l-1)%=n;
        xx[i]=(r%l+l)%l;
    }
    sort(xx+1,xx+n+1);
    c=(c+n)%n;
    fo(i,c+1,n)
        printf("%d\n",xx[i]);
    fo(i,1,c) printf("%d\n",xx[i]);
}