#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int a,s; cin >>a>>s;
  if(a>s){
    cout << a-s;
  }
  else{
    cout << "0";
  }
}