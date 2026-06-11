#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int gi(){
  char ch=getchar();int x=0,q=0;
  while(ch<'0' || ch>'9') ch=='-'?q=1:0,ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int z[20];
int gc(){
  char ch=getchar();
  while(ch!='Y'&&ch!='N') ch=getchar();
  return ch=='Y';
}
int main(){
  int d=0;
  for (ll i=1; i<=1e10; i*=10){
    cout<<"? "<<i<<endl;
    z[++d]=gc();
  }
  if (z[d]==1){
    for (ll s=10; ; s*=10){
      cout<<"? "<<s-1<<endl;
      if (gc()){
	cout<<"! "<<s/10;
	return 0;
      }
    }
  }
  for (int i=1; i<=d; ++i)
    if (z[i]==0){
      --i;
      ll l=1,r=1,mid,ans;
      for (int j=1; j<=i; ++j)
	l*=10;
      r=l,l/=10;
      while(l<=r){
	mid=(l+r)>>1;
	cout<<"? "<<mid*10<<endl;
	if (gc()) ans=mid,r=mid-1;
	else l=mid+1;
      }
      cout<<"! "<<ans;
      return 0;
    }
  return 0;
}
