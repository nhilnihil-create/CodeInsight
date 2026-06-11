#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  int N; cin >> N;
  vector <int> P(N);
  for (int i = 0; i < N; i++){
    cin >> P[i]; P[i]--;
  }
  
  vector <int> A(N), B(N);
  for (int i = 0; i < N; i++){
    A[i] = 20001 * i + 1;
    B[i] = 20001 * (N - 1 - i) + 1;
  }

  for (int i = 0; i < N; i++){
    int now = P[i];
    A[now] += i;
  }
  
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i != N - 1) cout << " ";
    else cout << endl;
  }
  for (int i = 0; i < N; i++){
    cout << B[i];
    if (i != N - 1) cout << " ";
    else cout << endl;
  }  
  

  return 0;
}