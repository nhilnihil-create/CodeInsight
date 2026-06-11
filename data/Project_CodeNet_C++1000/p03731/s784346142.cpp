#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long x;
  cin >> x;

  vector<long long> v(n, 0);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  long long ans = 0;
  if(n == 1){
    ans = x;
  }
  else{
    for(int i = 0; i < n - 1; i++){
      if(v[i + 1] - v[i] > x){ ans += x; }
      else{ ans += v[i + 1] - v[i]; }
    }
    ans += x;
  }
  cout << ans << endl;

}