#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int n,cnt=1;
  long a[100000],t,maxa[100000],sa[100000];
  scanf("%d %ld",&n,&t);
  for(int i=0;i<n;i++){
    scanf("%ld",&a[i]);
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1)
      maxa[i]=a[i];
    else
      maxa[i]=max(maxa[i+1],a[i]);
  }
  for(int i=0;i<n;i++)
    sa[i]=a[i]-maxa[i];
  sort(sa,sa+n);
  for(int i=1;i<n;i++){
    //printf("%ld\n",sa[i]);
    if(sa[i]==sa[i-1])
      cnt++;
    else
      break;
  }
  printf("%d\n",cnt);
}