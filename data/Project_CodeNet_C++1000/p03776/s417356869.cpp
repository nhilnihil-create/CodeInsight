#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

ll comb(int n, int r){
  ll x = 1;
  if(2*r>n) r = n - r;
  rep(i,r){
    x *= n - i;
    x /= i + 1;
  }
  return x;
}

int main(){
  ll N;
  int A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  rep(i,N){
    cin >> v.at(i);
  }
  sort(v.begin(), v.end(), greater<ll>());
  long double sum = 0.0;
  rep(i,A){
    sum += v.at(i);
  }
  int num = 0;
  int chosen = 0;
  bool all_equal = true;
  int index = A;
  rep(i,N){
    if(v.at(i)==v.at(A-1)){
      num++;
      if(i<A) chosen++;
    }
    if(i<A&&v.at(i)!=v.at(0)) all_equal = false;
    if(i>=A&&all_equal&&v.at(i)==v.at(A-1)){
      index = max(index,i+1);
    }
  }
  ll mtd = 0;
  if(all_equal){
    for(int i=A; i<=min(index,B); i++){
      mtd += comb(num,i);
    }
  }else{
    mtd += comb(num,chosen);
  }
  cout.precision(10);
  cout << fixed << sum/A << endl;
  cout << mtd;
  return 0;
}