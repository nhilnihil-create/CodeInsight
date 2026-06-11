#include <bits/stdc++.h>
using namespace std;

int main(){
  int fx, fy, tx, ty;
  cin >> fx >> fy >> tx >> ty;
  
  int xx = tx-fx;
  int yy = ty-fy;
  
  for (int i = 0; i<xx; i++){
  	cout << "R";
  }
  for (int i = 0; i<yy; i++){
    cout << "U";
  }
  for (int i = 0; i<xx; i++){
    cout << "L";
  }
  for (int i = 0; i<yy; i++){
    cout << "D";
  }
  cout << "D";
  for (int i = 0; i<xx+1; i++){
  	cout << "R";
  }
  for (int i = 0; i<yy+1; i++){
    cout << "U";
  }
  cout << "L";
  cout << "U";
  for (int i = 0; i<xx+1; i++){
    cout << "L";
  }
  for (int i = 0; i<yy+1; i++){
    cout << "D";
  }
  cout << "R" << endl;
}