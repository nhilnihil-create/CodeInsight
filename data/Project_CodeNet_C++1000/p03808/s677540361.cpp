#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pp=pair<ll,pair<int,int>>;
using Graph=vector<vector<int>>;

int main(){
  ll N;
  cin>>N;
  vector<ll> A(N);
  ll sum=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum+=A.at(i);
  }

  if(sum%(N*(N+1)/2)!=0){
    cout<<"NO"<<endl;
  }else{
    ll count=sum/(N*(N+1)/2);
    ll a=0;
    bool flag=true;
    for(int i=0;i<N;i++){
      if(A.at(i)-count<0){
        flag=false;
      }
    }
    for(int i=0;i<N-1;i++){
      if((count-A.at(i+1)+A.at(i))%N!=0){
        flag=false;
      }else{
        a+=(count-A.at(i+1)+A.at(i))/N;
        if(A.at(i)-(count-A.at(i+1)+A.at(i))/N*(N-1)-count<0){
          flag=false;
        }
      }
    }
    if((count-A.at(0)+A.at(N-1))%N!=0){
      flag=false;
    }else{
      a+=(count-A.at(0)+A.at(N-1))/N;
      if(A.at(N-1)-(count-A.at(0)+A.at(N-1))/N*(N-1)-count<0){
        flag=false;
      }
    }
    if(a!=count){
      flag=false;
    }
    if(flag){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
}
