#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i <(int)(n); i++)

using namespace std;

int main(){
  int N;
  cin >> N;

  int num = 3 * N;

  long long a[num];
  rep(i, num){
    cin >> a[i];
  }

  sort(a, a + num, greater<int>());

  long long ans = 0;
  for(int i = 0; i < 2 * N; i++){
    if(i%2 == 1){
      ans += a[i];
    }
    
  }

  cout << ans << endl;

  return 0;

}