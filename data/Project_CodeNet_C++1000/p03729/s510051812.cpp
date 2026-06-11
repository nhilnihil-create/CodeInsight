#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  string a, b, c;
  cin >> a >> b >> c;
  if(a.substr(a.length()-1,1) != b.substr(0,1)){
    cout << "NO" << endl;
    return 0;
  }
  if(b.substr(b.length()-1,1) != c.substr(0,1)){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
