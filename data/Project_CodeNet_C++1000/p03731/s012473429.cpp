#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  long n, T;
  cin >> n >> T;
  long t[n];
  for(int i = 0; i < n; i++) cin >> t[i];

  long sum_water = T;
  for(int i = 1; i < n; i++) {
    sum_water += min((t[i]-t[i-1]), T);
  }
  cout << sum_water << endl;
  return 0;
}
