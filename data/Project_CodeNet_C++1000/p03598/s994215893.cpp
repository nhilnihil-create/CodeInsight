#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, i, dis = 0;
  cin >> N;
  cin >> K;
  int x[N];
  for ( i = 0; i < N; i++)
  {
    cin >> x[i];
  }
  // manipulate
  for (i = 0; i < N; i++)
  {
    if (x[i] <= (K - x[i]))
    {
      dis += x[i] * 2;
    }else
    {
      dis += (K - x[i]) * 2;
    }
  }

  // output
  cout << dis << endl;


  return 0;
}