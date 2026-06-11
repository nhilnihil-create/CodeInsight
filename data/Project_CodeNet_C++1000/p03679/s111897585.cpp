#include<bits/stdc++.h>
using namespace std;

int main(){
  int x, a, b;
  cin >> x >> a >> b;
  if(a-b >= 0) cout << "delicious\n" << endl;
  else if(b <= a+x) cout << "safe\n" << endl;
  else cout << "dangerous\n" << endl;
}
