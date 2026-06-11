#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<int>ans(N);
  if(N%2==0){
    rep(i,N){
    	cin>>A[i];
    	if(i%2==0)ans[(N+i)/2]=A[i];
	    else ans[(N-i-1)/2]=A[i];
  	}
  }
  else{
    rep(i,N){
      cin>>A[i];
      if(i%2==0)ans[(N-i-1)/2]=A[i];
      else ans[(N+i)/2]=A[i];
    }
  }
  rep(i,N){
    cout<<ans[i]<<(i==N-1? "":" ");
  }
  cout<<endl;
}