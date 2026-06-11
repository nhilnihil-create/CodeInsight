#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, t;
  cin >> N >> t;

  if (N < t){
    cout << 0 << endl;
  }
  else
  {
    cout << N - t << endl;
  }
  
}