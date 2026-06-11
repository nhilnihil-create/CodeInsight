#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  cout << "#" ;
  for (int i = 0; i < w; i++){
    cout << "#";
  }
  

  cout << "#" << endl;
  string p;
  for (int i = 0; i < h; i++){
    cin >> p;
    cout << "#" << p << "#" << endl;
  }
  cout << "#" ;
  for (int i = 0; i < w; i++){
    
    cout << "#";
  }  
  cout << "#"  << endl;
  
}
