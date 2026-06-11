#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N,M;
  cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  ll cnt=1;
  int flag=0;
  ll i=0;
  
  while(i<N-1){
    if(A.at(i)>A.at(i+1) && flag == 0){
      flag = 1;
    }else if(A.at(i)<A.at(i+1) && flag == 0){
      flag = -1;
    }else if(A.at(i) < A.at(i+1) && flag == 1){
      cnt++;
      flag = 0;
    }else if(A.at(i) > A.at(i+1) && flag == -1){
      cnt++;
      flag = 0;
    }
    i++;
  }
  
  cout << cnt << endl;
  
  return(0);
}