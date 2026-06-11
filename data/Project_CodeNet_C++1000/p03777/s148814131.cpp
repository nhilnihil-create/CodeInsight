#include<iostream>
using namespace std;
int main(){
  char s,t;cin >> s >> t;
  if(s == 'H' ) cout << t << endl;
  else if(t == 'D') cout << 'H' << endl;
  else cout << 'D' << endl;
}