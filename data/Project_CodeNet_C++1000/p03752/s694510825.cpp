#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main(){
  int n,k,a[100],sum,ans=-1,ma,q;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<(1<<(n));i++){
    sum=0;
    q=1;
    for(int j=0;j<n;j++){
      if(j==0) ma=a[0];
      if(i&(1<<j)&&j!=0){
	if(ma>=a[j]){
	  sum+=abs(a[j]-(ma+1));
	  ma+=1;
	  q++;
	}
	else{
	  q++;
	  ma=max(ma,a[j]);
	}
      }
      else{
	if(ma<a[j]){
	  q++;
	  ma=a[j];
	}
      }
    }
    //cout<<q<<"\n";
    if(ans==-1&&q>=k) ans=sum;
    if(q>=k) ans=min(ans,sum);
  }
  cout<<ans<<"\n";
}
