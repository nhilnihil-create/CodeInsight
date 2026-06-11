#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<queue>
#include<ctime>
#include<vector>
using namespace std;
inline int rd(){
  register char ch=getchar();
  register bool flag=false;
  register int res=0;
  while(ch<'0'||ch>'9'){flag=(ch=='-');ch=getchar();}
  while(ch>='0'&&ch<='9'){
    res=(res<<3)+(res<<1)+ch-'0';ch=getchar();}
  if(flag)res=-res;
  return res;
}
int n;
#define N 1000010
#define mod 1000000007
int f[N],sf[N];
inline int upd(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void work(){
  n=rd();
  int i,j;
  //n^2 dp 很好想，发现可以前缀和优化一下
  f[0]=1;sf[0]=1;
  for(i=1;i<=n;i++)
    {if(i>=3)
	f[i]=sf[i-3];//恰好在f结尾的
      //add more then 1
      upd(f[i],f[i-1]);
      sf[i]=sf[i-1];
      upd(sf[i],f[i]);
      //printf("%d ",f[i]);
    }
  int ans=0,n2=1LL*(n-1)*(n-1)%mod;
  for(i=0;i<=n-2;i++)
    upd(ans,1LL*f[i]*(n2+(i+1))%mod);//可以乱选择,限制必须超过n
  upd(ans,1LL*f[n-1]*(n-1)%mod);//必须限制超过n
  upd(ans,f[n]);//必须一样
  printf("%d\n",ans);
}
int main(){
  work();
  return 0;
}
