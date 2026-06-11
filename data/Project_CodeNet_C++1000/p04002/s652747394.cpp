#include<map>
#include<cstdio>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
map<pii,int> mp;
long long cnt[10],h,w,n;
int max(int x,int y)
{
 return (x>=y)? x:y;
}
int min(int x,int y)
{
  return (x<y)? x:y;
}
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{   
	h=read(),w=read(),n=read();
    int i,j;
while(n--)
{
  int x=read(),y=read();
  for (i=max(1,x-2);i<=min(h-2,x);++i)
  {
    for (j=max(1,y-2);j<=min(w-2,y);++j)
	{
      mp[pii(i,j)]++; 
    }
    }
  }
for (map<pii,int>::iterator iter=mp.begin();iter!=mp.end();iter++) cnt[iter->second]++,n++;
ll ans=1ll*(h-2)*(w-2);
 printf("%lld\n",ans-n-1);
for (i=1;i<=9;++i) printf("%lld\n",cnt[i]);
}