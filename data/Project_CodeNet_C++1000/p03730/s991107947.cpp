#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int a,b,c;
  cin >>a >>b >>c;
  bool can = false;
  for(int i = 1; i<=b; i++){
    if(i*a%b==c) can = true;
  }
  if(can) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0; 
}
