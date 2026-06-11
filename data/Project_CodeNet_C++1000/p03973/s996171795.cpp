#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  ll ans=A[0]-1;
  ll a=1;
  for(int i=1;i<N;i++){
    if(A[i]>2*a){
      ans+=(A[i]-1)/(a+1);
    }else{
      if(A[i]>a+1){
        ans++;
      }
      if(A[i]==a+1){
        a=A[i];
      }
    }
  }
  cout<<ans<<endl;
}
