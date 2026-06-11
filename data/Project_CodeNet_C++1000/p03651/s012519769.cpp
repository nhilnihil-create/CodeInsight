#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
  if(b==0)return a;
  else return gcd(b, a%b);
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int>a(n);
  for(int i=0; i<n; i++)cin >> a[i];
  int g=a[0], m=a[0];
  for(int i=1; i<n; i++){
    g = gcd(g, a[i]);
    m = max(m, a[i]);
  }
  if(m-k>=0 && (m-k)%g==0)cout << "POSSIBLE";
  else cout << "IMPOSSIBLE";
  return 0;
}
  