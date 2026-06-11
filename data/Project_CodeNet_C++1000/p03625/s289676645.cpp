#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double f(double x){
  if(x < 0){x *= (-1);}
  return x;
}

int main(){
  unsigned long long n;
  cin >> n;
  vector<unsigned long long> v(n, 0);
  for(unsigned long long i = 0; i < n; i++){
    cin >> v[i];
  }
  bool f = false;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  vector<unsigned long long> w(0);
  for(unsigned long long i = 0; i < n-1; i++){
    if(v[i] == v[i+1]){w.push_back(v[i]); i++;}
    if(w.size() == 2){break;}
  }
  //for(auto c : w){cout << c << endl;}
  if(w.size() >= 2){
    unsigned long long k = w[0] * w[1];
    cout << k << endl;
  }
  else{
    cout << 0 << endl;
  }
}       