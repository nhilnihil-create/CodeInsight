#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main(){
  string t;
  cin >> t;
  int n,w,s,e;
  n = count(t.begin(),t.end(),'N');
  w = count(t.begin(),t.end(),'W');
  s = count(t.begin(),t.end(),'S');
  e = count(t.begin(),t.end(),'E');
  if( ( ( n == 0 && s == 0 ) || ( n > 0 && s > 0 ) ) &&
      ( ( w == 0 && e == 0 ) || ( w > 0 && e > 0 ) )    ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}