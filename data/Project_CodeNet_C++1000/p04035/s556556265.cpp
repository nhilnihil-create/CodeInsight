#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 2000000
#define MOD 1000000007

int main(){
  ll N,L;
  cin>>N>>L;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  int k=-1;
  for(int i=0;i<N-1;i++){
    if(a.at(i)+a.at(i+1)>=L){
      k=i+1;
    }
  }
  if(k==-1){
    cout<<"Impossible"<<endl;
  }else{
    cout<<"Possible"<<endl;
    for(int i=1;i<k;i++){
      cout<<i<<endl;
    }
    for(int i=N-1;i>k;i--){
      cout<<i<<endl;
    }
    cout<<k<<endl;
  }
}
