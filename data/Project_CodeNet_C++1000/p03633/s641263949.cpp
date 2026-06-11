#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if (a%b == 0){
    return(b);
  }else{
    return(gcd(b, a%b));
  }
}

long long lcm(long long a, long long b){
  return a / gcd(a, b) * b;
}

int main() {
  int N;
  cin >> N;
  vector<long long> T(N);
  long long lcm_tmp = 1;
  for(int i=0;i<N;i++){
    cin >> T.at(i);
    lcm_tmp = lcm(T.at(i),lcm_tmp);
  }
  cout << lcm_tmp << endl;

}