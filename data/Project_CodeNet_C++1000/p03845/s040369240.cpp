#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int N,M;
  cin >> N;
  vector<ll> T(N);
  ll T_sum=0;
  for(int i=0;i<N;++i){
    cin >> T.at(i);
    T_sum+=T.at(i);
  }
  cin >> M;
  vector<pair<int,ll>> drink(M);
  int P;
  ll X;
  for(int i=0;i<M;++i){
    cin >> P >> X;
    drink.at(i)=make_pair(P,X);
  }

  for(int i=0;i<M;++i){
    int P=drink.at(i).first-1;
    ll X=drink.at(i).second;
    cout << T_sum-T.at(P)+X << endl;
  }
  
  return 0;
}
