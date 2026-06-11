#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll n,k,df,ans,tmp;
  cin >> n >> k;
  ll a[n],psum[n],sum[n];
  fill(sum,sum+n,0);
  fill(psum,psum+n,0);
  ans = -10000000000000;
  for(int i=0;i<n;i++){
    if(i!=0){
      psum[i]=psum[i-1];
      sum[i]=sum[i-1];
    }
    cin >> a[i];
    sum[i]+=a[i];
    psum[i]+=max((ll)0,a[i]);
  }
  for(int i=0;i+k<=n;i++){
    df=i+k-1;
    tmp=0;
    if(i!=0){
      tmp+=psum[i-1];
      tmp+=max(sum[df]-sum[i-1],(ll)0);
    }else{
      tmp+=max(sum[df],(ll)0);
    }
    if(df!=n-1){
      tmp+=psum[n-1]-psum[df];
    }
    ans = max(tmp,ans);
  }
  cout << ans << endl;
}
