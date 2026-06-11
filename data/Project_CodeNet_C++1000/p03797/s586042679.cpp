#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m,scc;
  cin >> n >> m;
  
  if(m>2*n){
    scc = n+(m-2*n)/4;
  }
  else{
    scc = m/2;
  }

  cout << scc << endl;
}