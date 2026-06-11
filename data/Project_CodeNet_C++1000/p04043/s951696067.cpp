#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  string s = a+b+c;
  if(s=="557" || s=="575" || s=="755")
    cout << "YES" << endl;
  else
    cout << "NO" <<endl;
}
