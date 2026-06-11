#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <numeric>
#include <cfloat>

using namespace std;

#define MOD 1000000007

int main(int argc, char* argv[]){
  int N;
  cin >> N;

  vector<int> x(N);

  for(int i=0; i<N; i++){
    cin >> x[i];
  }

  long long ans=1;
  int count = 1;

  for(int i=1; i<N; i++){
    count++;
    if(x[i] < 2*count-1){
      ans *= count;
      ans %= MOD;
      count--;
    }
  }
  for(int i=1; i<=count; i++){
    ans *= i;
    ans %= MOD;
  }

  cout << ans << endl;
  
  return 0;
}