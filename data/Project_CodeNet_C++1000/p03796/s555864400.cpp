#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
#define ll long long
#define ld long double

int main(){
  int n;
  cin >> n;
  
  ll power = 1;
  for(int i = 1; i <= n; i++){
    power *= i;
    power %= 1000000007;
  }
  cout << power << endl;
}