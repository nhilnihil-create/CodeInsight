#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

#define MAX 200003
#define MOD 1000000007

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  vector<ll> v(N);
  for(int i=0;i<N;i++){
    cin>>v.at(i);
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  ll sum=0;
  for(int i=0;i<A;i++){
    sum+=v.at(i);
  }
  ll V=v.at(A-1);
  ll count1=0;
  ll count2=0;
  for(int i=0;i<N;i++){
    if(v.at(i)==V){
      count1++;
      if(i<A){
        count2++;
      }
    }
  }
  ll ans=0;
  ll com=1;
  for(int i=0;i<count2;i++){
    com*=(count1-i);
    com/=(i+1);
  }
  ans+=com;
  if(v.at(0)==V){
    for(ll i=count2;i<min<ll>(B-A+count2,count1);i++){
      com*=(count1-i);
      com/=(i+1);
      ans+=com;
    }
  }
  printf("%lf\n",(double)sum/(double)A);
  cout<<ans<<endl;
}
