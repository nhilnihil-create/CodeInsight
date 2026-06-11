#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b){
  int64_t buf;
  while(b > 0){
    buf= a;
    a= b;
    b= buf%b;
  }
  return a;
}

int main(){
  int N,target;
  cin >> N >> target;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  int Amax= *max_element(data.begin(), data.end());
  int g= data.at(0);
  for(int i=1; i<N; i++){
    g= gcd(g, data.at(i));
  }

  string ans= (Amax >= target && (Amax- target) % g==0) ? "POSSIBLE"
                                                        : "IMPOSSIBLE";
  cout << ans << endl;
}