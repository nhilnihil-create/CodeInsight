#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int a[] = {1, 3, 5, 7, 8, 10, 12};
  int b[] = {4, 6, 9, 11};
  int c[] = {2};
  int x, y;
  cin >> x >> y;
  char xg, yg;
  for(int i=0; i<7; i++){
    if(x==a[i]) xg='a';
    if(y==a[i]) yg='a';
  }
  for(int i=0; i<4; i++){
    if(x==b[i]) xg='b';
    if(y==b[i]) yg='b';
  }
  for(int i=0; i<1; i++){
    if(x==c[i]) xg='c';
    if(y==c[i]) yg='c';
  }
  if(xg==yg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
