#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin >> n;
  
  int i = 1;
  int64_t power = 1;
  while(i <= n){
    power = power * i % 1000000007;
    i++;
  }
  
  cout << power << endl;
  
}