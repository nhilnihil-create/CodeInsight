#include<iostream>
using namespace std;
int main(){
  int a,b,c;cin >>a >> b>> c;
  if(c - b > a) cout << "dangerous" << endl;
  else if(c - b <= 0) cout << "delicious" << endl;
  else cout << "safe" << endl;
}