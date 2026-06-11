#include<cstdio>

using namespace std;

int main(){
  int n;
  long a,b,h[100000],l,r,mid,cnt;
  scanf("%d %ld %ld",&n,&a,&b);
  for(int i=0;i<n;i++)
    scanf("%ld ",&h[i]);
  l=0;
  r=1000000000;
  while(l<=r){
    mid=(l+r)/2;
    cnt=0;
    for(int i=0;i<n;i++)
      if(b*mid<h[i]){
        cnt+=(h[i]-b*mid)/(a-b);
        if((h[i]-b*mid)%(a-b)!=0)
          cnt++;
      }
    if(cnt<=mid)
      r=mid-1;
    else
      l=mid+1;
  }
  printf("%ld\n",l);
}