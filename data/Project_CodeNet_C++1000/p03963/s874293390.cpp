#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>
#include<numeric>
#include<stdlib.h>

using namespace std;

int main()
{

  int N, K;
  cin >> N >> K;

  if(N == 1){
    cout << K << endl;
    return 0;
  }
  int ans = pow(K-1,N-1);
  ans *= K;
  cout << ans << endl;

  return 0;
}
