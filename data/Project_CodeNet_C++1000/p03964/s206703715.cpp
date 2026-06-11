#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  long long int pa, pb;
  cin >> pa >> pb;
  for(int i=1; i<n; i++){
    long long int a, b;
    cin >> a >> b;
    long long int j = max((pa+a-1)/a,(pb+b-1)/b);
    pa=a*j;
    pb=b*j;
  }
  long long int ans = pa+pb;
  cout << ans << endl;
  return 0;
}