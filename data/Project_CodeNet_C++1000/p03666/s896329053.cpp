#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>
#include <cmath>
#include <deque>

using namespace std;

long long a[2000];
int main(){
  int N;
  long long A;
  long long B;
  long long C;
  long long D;

  cin >> N >> A >> B >> C >> D;
  for(int i = 0; i < N; i++){
    long long lower_bound = A + C * i - (N - 1 - i) * D;
    long long upper_bound = A + D * i - (N - 1 - i) * C;
    if(lower_bound <= B && B <= upper_bound){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  
  return 0;
}
