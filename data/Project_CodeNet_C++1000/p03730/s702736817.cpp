#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int r[110];
  int sum = 0;
  if(c == 0) {
    cout << "YES" << endl;
    return 0;
  }
  for(int i = 1; i < b; i++){
    r[i] = (a*i) % b;
    if(r[i] == 0) continue;
    if(c % r[i] == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
