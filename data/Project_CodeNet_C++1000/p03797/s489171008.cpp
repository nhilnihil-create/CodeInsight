#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll M,N,ans = 0,rest;
  cin >> M >> N;
  
  if(M * 2 >= N){
    ans = N / 2;
  }
  else{
    rest = N - M * 2;
    ans = M + rest / 4;
    
  }
  cout << ans << endl;
}