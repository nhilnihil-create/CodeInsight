#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main(){
  int n,k,x,y;
  cin >> n >> k >> x >> y;
  if(n>k){
    cout << k*x+(n-k)*y << endl;
  }else cout << n*x << endl;
  return 0;
}
