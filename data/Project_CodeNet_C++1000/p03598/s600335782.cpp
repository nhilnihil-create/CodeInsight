#include <iostream>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for(int i = 0; i < N; i++){
    int x;
    cin >> x;
    if((x * 2) < ((K - x) * 2)) ans += x * 2;
    else ans += (K - x) * 2;
  }
  cout << ans << endl;
}