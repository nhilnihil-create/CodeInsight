#include <iostream>
using namespace std;

int main(){
  int N; cin >> N;
  int a[N];
  int sum = 0;
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int M; cin >> M;
  for(int i = 0; i < M; ++i) {
	int p, x; cin >> p >> x;
    cout << sum - a[p-1] + x << endl;
 
  }
  return 0; 
}
