#include <bits/stdc++.h>
using namespace std;

int main() {
	int H , W ;
  	cin >> H >> W ;
  	for(int i = 0; i < W + 2; i++){
    	cout << "#";
    }
  	cout << endl;
  	string s;
  	char a;
  	for(int i = 0; i < H; i++){
      	cin >> s;
      	cout << "#";
    	for(int j = 0; j < W; j++){
          	a = s.at(j);
        	cout << a;
        }
        cout << "#" << endl;
    }
    for(int i = 0; i < W + 2; i++){
    	cout << "#";
    }
  	cout << endl;
}