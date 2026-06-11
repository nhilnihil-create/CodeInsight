#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  long long N, K;
  cin >> N >> K;
  long long a, b;
  pair<long long, long long> p[N];
  rep(i, N){
    cin >> a >> b;
    p[i].first = a;
    p[i].second = b;
  }
  //

  sort(p, p+N);

  int i = 0;
  long long sum = 0;
  while(sum < K){
    sum += p[i].second;
    i++;
  }

  cout << p[i-1].first << endl;

  return 0;
}
