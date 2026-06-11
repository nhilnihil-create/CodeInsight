#include <bits/stdc++.h>
using namespace std;
 
int main() {
	//
  int H, W;
  cin >> H >> W;
  for(int i=0; i<W+2; i++)
    cout << '#';
  cout << endl;
  
  for(int i=0; i<H; i++){
    cout << '#';
    
    vector<char> pic(W);
     for(int i=0; i<W; i++){
      cin >> pic. at(i);
      cout << pic. at(i);
    }
    cout << "#" << endl;
  }
  
    for(int i=0; i<W+2; i++)
    cout << "#";
  cout << endl;
 }