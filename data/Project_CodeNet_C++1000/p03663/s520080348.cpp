#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool query(long long x){//if N is lexicographically <x
  if(x==0)return false;
  while(x<=10000000000ll)x=x*10;
  printf("? %lld\n",x-1);
  fflush(stdout);
  char buf[10];
  scanf("%s",buf);
  return buf[0]=='Y';
}
bool onlyone(int x){
  if(x==0)return false;
  while(x%10==0)x/=10;
  return x==1;
}
bool ok(int ans){
  char buf[10];
  printf("? %lld\n",ans*10ll-1);fflush(stdout);
  scanf("%s",buf);
  if(onlyone(ans)){
    return buf[0]=='Y';
  }else{
    return buf[0]=='N';
  }
}
int ans=0;
void getfirst(){
  int l=1,r=9;
  while(l<=r){
    if(l==r&&l==1){
      ans=1;return;
    }
    int mid=(l+r)>>1;
    if(query(mid))r=mid-1;
    else l=mid+1;
  }
  ans=r;
}
int main(){
  getfirst();
  while(1){
    int l=0,r=9;
    while(l<=r){
      int mid=(l+r)>>1;
      if(query(ans*10+mid))r=mid-1;
      else l=mid+1;
    }
    if(r==-1)r++;
    if(r==0&&ok(ans)){
      printf("! %d\n",ans);break;
    }
    ans=ans*10+r;
    if(ans*10ll>1000000000){
      printf("! %d\n",ans);break;
    }
  }
  return 0;
}
