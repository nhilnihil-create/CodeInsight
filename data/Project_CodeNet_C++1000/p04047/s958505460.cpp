#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() 
{
  int N; cin >> N;
  N *= 2;
  vector<int> L(N, 0);
  for(int i = 0; i < N; i++) cin >> L[i]; 
  sort(L.rbegin(), L.rend());
  
  int ingredients = 0;
  for(int i = 1; i < N; i+=2) {
    ingredients += L[i];
  }
  
  cout << ingredients << endl;
  
  return 0;
}