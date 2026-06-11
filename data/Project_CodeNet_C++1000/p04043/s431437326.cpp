#include<iostream>
using namespace std;

int main(){
  int a=0,b=0,c;
  for(int i=0; i<3; i++){
    cin >> c;
    if(c==7) a++;
    else if(c==5) b++;
  }
  if(a == 1 && b == 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}