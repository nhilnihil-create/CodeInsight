#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m;
  cin >> n >> m;
  if(n > m/2){
    cout << m/2 << endl;
    return 0;
  }
  else{
    cout << n+(m-2*n)/4 << endl;
    return 0;
  }
}
