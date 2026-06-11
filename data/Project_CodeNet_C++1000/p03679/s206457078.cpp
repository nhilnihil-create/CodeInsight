#include<iostream>
using namespace std;
int main(){
  int a,b,c,ans;
  cin >> a >> b >> c;
  ans = c-b;
  if (ans <= 0){
    cout << "delicious" << endl;
  } else if (ans <= a) {
    cout << "safe" << endl;
  } else {
    cout << "dangerous" << endl;
  }
}
  