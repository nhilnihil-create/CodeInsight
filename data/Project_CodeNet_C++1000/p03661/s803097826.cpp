#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  long long asum[200000];
  long long a;
  cin >> asum[0];
  for(int i=1; i<N; i++){
    cin >> a;
    asum[i]=asum[i-1]+a;
  }
  long long minimum=200000000000000;
  for(int i=0; i<N-1; i++){
    minimum=min(minimum,abs(asum[i]-(asum[N-1]-asum[i])));
  }
  cout << minimum << endl;
}