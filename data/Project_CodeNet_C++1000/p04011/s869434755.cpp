#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,k,x,y;
  cin >> n >> k >> x >> y;
  if(n <= k){
    cout << n*x << endl;
  }else{
    cout << k*x + (n-k)*y << endl;
  }
  return 0;
}
