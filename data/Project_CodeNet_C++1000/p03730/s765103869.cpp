#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int A, B, C; cin >> A >> B >> C;
  int m = A%B; 
  if(m == 0) {cout << "NO" << endl; return 0;}
  int sum = m;
  
  rep(i,150){
    if(sum%B == C){ cout << "YES" << endl; return 0;}
    else sum +=m;
  }
  cout << "NO" << endl;
  return 0;
}