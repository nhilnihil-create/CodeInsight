#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,j,sum=0,sum2=0;
  cin>>n;
  vector<ll> a(n),b(n),c(n);
  for(i=0;i<n;i++){
	cin>>a[i];
    sum+=a[i];
  }
  ll m=n*(n+1)/2,t;
  if(sum%m!=0){
    cout<<"NO"<<endl;
    return 0;
  }else{
	t=sum/m;
  }
  for(i=0;i<n-1;i++){
	b[i]=a[i+1]-a[i];
  }
  b[n-1]=a[0]-a[n-1];
  
  for(i=0;i<n;i++){
	if(t-b[i]<0||(t-b[i])%n!=0){
		cout<<"NO"<<endl;
      	return 0;
    }
  }
	
  cout<<"YES"<<endl;
  
}
  