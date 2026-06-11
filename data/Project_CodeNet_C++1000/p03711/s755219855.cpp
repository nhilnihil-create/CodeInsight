#include <iostream>
#include <vector>
using namespace std;
int main(){
  int x,y;
  cin >> x >> y;
  vector<int> a{0,1,3,1,2,1,2,1,1,2,1,2,1};
  if(a[x]==a[y]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}