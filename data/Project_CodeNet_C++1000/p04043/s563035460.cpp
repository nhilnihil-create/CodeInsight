#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  
  if (a+b+c=="575" || a+c+b=="575" || b+a+c=="575" ||
      b+c+a=="575" || c+a+b=="575" || c+b+a=="575") {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}