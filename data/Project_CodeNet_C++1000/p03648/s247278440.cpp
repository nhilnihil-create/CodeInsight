#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k;
ll in[51];

int main() {
  cin >> k;

  ll n = 50;
  ll c = k / 50;

  
  for(int i = 0; i < n; i++) in[i] = n-1 + c;

  for(int i = 0; i < k % 50 ; i++) {
    in[i] += n;
  for(int j = 0; j < n; j++) if(i != j) in[j] -= 1;
  }
  cout << n << endl;
  for(int i = 0; i < n - 1; i++) cout << in[i] <<" ";
  
  cout << in[n-1]<<endl;
  

}
