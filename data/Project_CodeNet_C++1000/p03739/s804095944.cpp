#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);

  ll sump=0; 
  ll ansp=0;
  ll summ=0;
  ll ansm=0;
  rep(i,N){
    sump += A.at(i);
    if(i%2==0 && sump<=0){
      ansp += -sump+1;
      sump = 1;
    }
    if(i%2==1 && sump>=0){
      ansp += sump+1;
      sump = -1;
    }
  }
  
  rep(i,N){
    summ += A.at(i);
    if(i%2==1 && summ<=0){
      ansm += -summ+1;
      summ = 1;
    }
    if(i%2==0 && summ>=0){
      ansm += summ+1;
      summ = -1;
    }
  }
  cout << min(ansp, ansm) << endl; 
  return 0;
}
