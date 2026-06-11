#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 2100000000
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<ll> a(3*N);
  for(int i=0;i<3*N;i++){
    cin>>a.at(i);
  }

  priority_queue<ll,vector<ll>,greater<ll>> A;
  priority_queue<ll> B;
  vector<ll> sum_A(N+1,0);
  for(int i=0;i<N;i++){
    sum_A.at(0)+=a.at(i);
    A.push(a.at(i));
  }
  for(int i=N;i<2*N;i++){
    ll x=A.top();
    if(a.at(i)>x){
      sum_A.at(i-N+1)=sum_A.at(i-N)+a.at(i)-x;
      A.pop();
      A.push(a.at(i));
    }else{
      sum_A.at(i-N+1)=sum_A.at(i-N);
    }
  }
  vector<ll> sum_B(N+1,0);
  for(int i=2*N;i<3*N;i++){
    sum_B.at(N)+=a.at(i);
    B.push(a.at(i));
  }
  for(int i=2*N-1;i>=N;i--){
    ll x=B.top();
    if(a.at(i)<x){
      sum_B.at(i-N)=sum_B.at(i-N+1)+a.at(i)-x;
      B.pop();
      B.push(a.at(i));
    }else{
      sum_B.at(i-N)=sum_B.at(i-N+1);
    }
  }

  ll ans=sum_A.at(0)-sum_B.at(0);
  for(int i=0;i<N+1;i++){
    ans=max<ll>(ans,sum_A.at(i)-sum_B.at(i));
  }
  cout<<ans<<endl;
}
