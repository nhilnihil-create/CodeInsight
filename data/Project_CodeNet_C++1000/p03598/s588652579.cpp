#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  vector<int> x(n);
  for(int i=0; i<n; i++){
    cin>>x[i];
  }
  
  int ans=0;
  for(int i=0; i<n; i++){
    ans += 2*min(k-x[i], x[i]);
  }
  cout << ans <<endl;
}