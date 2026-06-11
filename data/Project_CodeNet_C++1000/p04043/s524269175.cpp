#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a;
  int e=0, f=0;
  for(int i=0;i<3;i++){
    cin >> a;
    if(a==5)e++;
    if(a==7)f++;
  }
  if(e==2&&f==1)cout << "YES";
  else cout << "NO";
}
