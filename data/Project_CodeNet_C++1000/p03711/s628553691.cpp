#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  char xg, yg;

  if(x==4 || x==6 || x==9 || x==11){
    xg='B';
  }
  else if(x==2){
    xg='C';
  }
  else{
    xg='A';
  }

  if(y==4 || y==6 || y==9 || y==11){
    yg='B';
  }
  else if(y==2){
    yg='C';
  }
  else{
    yg='A';
  }

  if(xg==yg){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

return 0;  
}