#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  long long N;
  cin >> N;

  long long power = 1;

  for (int i = 1; i <= N; i++)
  {
    power *= i;
    power %= 1000000007;
  }

  cout << power << endl;
  
}