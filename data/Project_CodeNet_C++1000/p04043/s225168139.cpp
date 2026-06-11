#include <iostream>

using namespace std;
int a,ans;

int main(){
  while(cin >> a){
    if (a!=5 && a!=7) {
      cout << "NO"; return 0;}
    ans+=a;}
  cout << (ans==17? "YES" : "NO");
  return 0;
}