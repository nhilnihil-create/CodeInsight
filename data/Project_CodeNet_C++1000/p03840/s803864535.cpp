#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  long a[7],b,ans=0;
  for(int i=0;i<7;i++)
    scanf("%ld",&a[i]);
  ans+=a[1];
  ans+=a[0]/2*2;
  ans+=(a[3]/2+a[4]/2)*2;
  if(a[0]&&a[3]&&a[4]){
    b=a[1];
    b+=(a[0]-1)/2*2;
    b+=((a[3]-1)/2+(a[4]-1)/2)*2;
    b+=3;
    ans=max(ans,b);
  }
  printf("%ld\n",ans);
}