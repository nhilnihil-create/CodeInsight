#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;cin>>n;
 	ll a[n];	
  	for(int i=0;i<n;i++){
      cin>>a[i];
    }
  	ll nsr[n];
  	stack<pair<ll, ll> > st;
  	for(int i=n-1;i>=0;i--){
      while(!st.empty()&&st.top().first>a[i]) st.pop();
      if(st.empty()) nsr[i]=n;
      else nsr[i]=st.top().second;
      st.push({a[i],i});
    }
//    for(int i=0;i<n;i++) cout<<nsr[i]<<" \n"[i==n-1];
  	ll dp[n+10]={0},sum=0;
  	for(int i=n-1;i>=0;i--){
      dp[i]=(nsr[i]-i)*a[i]+dp[nsr[i]];
      sum+=dp[i];
    }
	cout<<sum<<endl;
  	return 0;
}