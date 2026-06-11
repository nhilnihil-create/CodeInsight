#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int n,a,b; cin >> n >> a >> b;
  a = abs(n-a); b = abs(n-b);
  if(a>b){
    cout << "B";
  }
  else{
    cout << "A";
  }
}