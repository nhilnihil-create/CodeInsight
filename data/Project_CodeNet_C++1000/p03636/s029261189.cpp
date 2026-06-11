#include<iostream>
using namespace std;
int main(){
  string ss;
  cin >> ss;
  int len = ss.length();
  cout << ss[0] << len-2 << ss[len-1] << endl;
}