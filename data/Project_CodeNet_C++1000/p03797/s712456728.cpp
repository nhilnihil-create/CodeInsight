#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 5000
#define MOD 1000000007

int main(){
  ll N,M;
  cin>>N>>M;
  if(M-2*N>0){
    ll x=M/2-N;
    cout<<N+x/2<<endl;
  }else{
    cout<<M/2<<endl;
  }
}
