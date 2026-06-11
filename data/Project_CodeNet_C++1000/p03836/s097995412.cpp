#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int  a_x,a_y,b_x,b_y,i;
  cin >> a_x>>a_y>>b_x>>b_y;
  int x_distance = b_x - a_x;
  int y_distance = b_y - a_y;
  
  for ( i = 0; i<x_distance;i++){
    cout<< "R";
  }
  for ( i = 0; i<y_distance;i++){
    cout<< "U";
  }
  for ( i = 0; i<x_distance;i++){
    cout<< "L";
  }
  for ( i = 0; i<y_distance;i++){
    cout<< "D";
  }
  cout << "D";
  
  for ( i = 0; i<x_distance+1;i++){
    cout<< "R";
  }
  for ( i = 0; i<y_distance+1;i++){
    cout<< "U";
  }
  cout<< "L";
  cout<< "U";
  for ( i = 0; i<x_distance+1;i++){
    cout<< "L";
  }
  for ( i = 0; i<y_distance+1;i++){
    cout<< "D";
  }
  cout<<"R"<<endl;
}
