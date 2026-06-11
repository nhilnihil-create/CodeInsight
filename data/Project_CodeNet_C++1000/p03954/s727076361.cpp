#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,A[2000001],B[2000001],l,r,L,R,ans;

bool check(int x){
	L = 1, R = 2*n-1; 
  for(int i=1;i<=n*2-1;i++)
    B[i] = (A[i]>=x);
  
  for(int i=1;i<n;i++)
    if(B[i]==B[i+1]){
    	L = i+1;
    }
  
  for(int i=2*n-1;i>n;i--)
    if(B[i]==B[i-1]){
    	R = i-1;
    }
  
  if((n-L)<(R-n)){
  	return B[L] == 1;
  } else {
  	return B[R] == 1;
  }
}

int main(){
  
  cin>>n;
  for(int i=1;i<=n*2-1;i++){
  	cin>>A[i];
  }
  
  int l = 1, r = 2*n-1;
  while(l<=r){
  	int mid = (l+r)/2;
    if(check(mid)){
    	l = mid + 1;
      	ans = mid;
    } else {
    	r = mid - 1;
    }
  }
  cout<<ans<<endl;
}