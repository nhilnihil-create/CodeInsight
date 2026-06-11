#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a<c-b) cout << "dangerous" << endl;
  else if(b-c>=0) cout << "delicious" << endl;
  else cout << "safe" << endl;
}
