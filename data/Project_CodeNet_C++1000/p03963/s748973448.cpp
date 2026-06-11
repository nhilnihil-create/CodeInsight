#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;//nhow k kind
  cin >> n >> k;
  
  int64_t sum = k;
  n--;
  while(n > 0){
    sum *= k - 1;
    n--;
  }
  
  cout << sum << endl;
}