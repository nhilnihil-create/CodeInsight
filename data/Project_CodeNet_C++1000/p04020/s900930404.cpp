#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i(0);i<N;i++){
    cin>>A[i];
  }
  ll sum(0);
  vector<int> amari(N,0);
  for(int i(0);i<N;i++){
    if(A[i] == 0) continue;
    if(A[i]%2==0){
      if(i != 0 && amari[i-1] == 1){
        amari[i] = 1;
      }
      sum += A[i]/2;
    } else{
      if(i != 0 && amari[i-1] == 1) sum += A[i]/2+1;
      else{
        sum += A[i]/2;
        amari[i] = 1;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
