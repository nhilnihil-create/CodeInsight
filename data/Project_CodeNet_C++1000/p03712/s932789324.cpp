#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h;
  cin >> w;
  
  string line(w+2,'#');
  string read;
  cout << line << endl;
  for(int i = 0; i < h; i++){
    cin >> read;
    cout << '#' << read << '#' << endl;
  }
  cout << line << endl;
}