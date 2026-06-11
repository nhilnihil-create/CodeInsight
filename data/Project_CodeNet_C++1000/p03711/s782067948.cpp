#include<bits/stdc++.h>
using namespace std;

int main(){
  int X,Y;
  cin >> X >> Y;
  if (X == 2 || Y == 2){
    cout << "No" << endl;
  }
  else if ((X == 4 || X == 6|| X == 9|| X == 11) && (Y == 4 || Y == 6|| Y == 9|| Y == 11)){
    cout << "Yes" << endl;
  }
  else if ((X == 4 || X == 6|| X == 9|| X == 11) || (Y == 4 || Y == 6|| Y == 9|| Y == 11)){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}