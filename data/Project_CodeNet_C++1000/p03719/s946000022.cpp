#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int q,w,e; cin >>q>>w>>e;
  if(q <= e && w >= e){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}