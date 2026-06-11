#include <iostream>
using namespace std;
int main() {
  int n; cin>>n;
  int us=0, sm=0;
  for(us=1;;us++) {
    sm+=us;
    if (sm >= n) break;
  }
  for(int i=1;i<=us;i++) {
    if (sm - i == n) continue;
    cout<<i<<endl;
  }
}
