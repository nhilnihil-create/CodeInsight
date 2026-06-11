#include <iostream>

using namespace std;

int main(){
  string a;
  cin >> a;
  int ans = 0;
  for(int i=0;i<2;i++){
  if(a.at(i)=='9') ans=1;
  }
  if(ans) cout << "Yes";
  else cout << "No";
}