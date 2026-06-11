#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int N,P;
  cin >> N >> P;
  vector<int> a(N);
  for(int i = 0; i< N; i++){
    cin >> a.at(i);
  }
  bool b = true;
  for(int i = 0; i<N; i++){
    if(a.at(i) %2 != 0){
      b = false;
    }
  }
  long long ans;
  if(b){
    if(P == 0){
      ans =pow(2,N);
    }
    else{
      ans = 0;
    }
  }
  else{
    ans = pow(2,N-1);
  }
  cout << ans << endl;

}