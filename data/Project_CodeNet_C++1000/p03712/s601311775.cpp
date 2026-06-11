#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> vec(h);
  rep(i, h){
  	cin >> vec[i];
  }
  
  rep(i, w+2){
  	cout << "#";
  }
  cout << endl;
  
  rep(i, h){
  	cout << "#" << vec[i] << "#" << endl;
  }
  
  rep(i, w+2){
  	cout << "#";
  }
  cout << endl;
}