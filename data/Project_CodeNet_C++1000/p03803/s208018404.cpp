#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int a,b;
  cin >> a >> b;
  if(a==b)
    cout << "Draw" << endl;
  else if(a!=1&&b!=1){
    if(a<b)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
  else{
    if(a==1){
      cout << "Alice" << endl;
    }
    else
      cout << "Bob" << endl;
  }
}
