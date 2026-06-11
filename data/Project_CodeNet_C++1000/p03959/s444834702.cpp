#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  ll t[n],a[n];
  for(int i=0;i<n;i++){
    cin>>t[i];
  }
  for(int j=0;j<n;j++){
    cin>>a[j];
  }
  ll dp[n];
  dp[0]=1;
  if(n==1&& t[0]==a[0]){
    cout<<1<<endl;
  }else if(t[n-1]!=a[0]){
    cout<<0<<endl;
  }else{
    if(t[0]>a[0]||t[n-1]<a[n-1]){
      cout<<0<<endl;
      return(0);
    }
    for(int i=1;i<n-1;i++){
      if(t[i-1]<t[i]){
	dp[i]=dp[i-1];
	if(t[i]>a[i]){
	  cout<<0<<endl;
	  return(0);
	}
      }else if(t[i-1]==t[i]){
	if(a[i]>a[i+1]){
	  dp[i]=dp[i-1];
	  if(a[i]>t[i]){
	    cout<<0<<endl;
	    return(0);
	  }
	}else if(a[i]==a[i+1]){
	  dp[i]=(dp[i-1]*min(t[i],a[i]))%1000000007;
	}
      }
    }
    cout<<dp[n-2]<<endl;
  }
  return(0);
}
