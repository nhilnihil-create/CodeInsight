#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

  int N, K;
  cin >> N >> K;
  vector<int> l(N);
  for (int i=0; i<N; i++) cin >> l[i];

  int sum = 0;
  sort( (l).begin(), (l).end() );
  for (int i=0; i<K; i++){
    sum  += l[N-i-1];
  }

  cout << sum << "\n";
}
