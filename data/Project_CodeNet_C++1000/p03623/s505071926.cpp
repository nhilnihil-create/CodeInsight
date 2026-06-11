#include<iostream>
using namespace std;
int main(){
  int x,a,b;cin >> x >> a >>b;
  if(abs(a-x) < abs(b-x))
    cout << 'A';
  else
    cout <<'B';
}