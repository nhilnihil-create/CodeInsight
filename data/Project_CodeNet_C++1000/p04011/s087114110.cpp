#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll q,w,e,r; cin >>q>>w>>e>>r;
  if(q>w){
    cout << e*w+(q-w)*r;
  }
  else{
    cout << q*e;
  }
}