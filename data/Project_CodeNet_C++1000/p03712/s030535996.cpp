#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  
  int H, W;
  cin >> H >> W;
  vector<string> vec(H);
  rep(i, H){
  	cin >> vec.at(i);
  }
  rep(j, W + 2){
  	cout << "#";
  }
  	cout << endl;
  rep(k, H){
    cout << "#" + vec.at(k) + "#" << endl;}
  rep(l, W + 2){
  	cout << "#";
  }
  	cout << endl;
  	return 0;
}