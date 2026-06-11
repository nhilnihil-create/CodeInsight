#include<cstdio>
#include<algorithm>

using namespace std;

long long l,t,a[200000],dir[200000];

int main(){
  //printf("%d",-1/5);
  int n;
  scanf("%d%lld%lld",&n,&l,&t);
  for(int i=0;i<n;i++){
    scanf("%lld%lld",&a[i],&dir[i]);
    if(dir[i]==2)
      dir[i]=-1;
  }
  long long shift = 0;
  for(int i=0;i<n;i++){
    a[i]+=t*(dir[i]);
    shift+=(a[i]/l)-(a[i]%l<0);
    a[i]%=l;
    a[i]+=l;
    a[i]%=l;
    shift%=n;
    shift+=n;
    shift%=n;
  }
  shift%=n;
  shift+=n;
  shift%=n;
  sort(a,a+n);
  for(int i=0;i<n;i++){
      printf("%lld\n",a[(shift+i)%n]);
  }
}