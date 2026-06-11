#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  for (int i = 0; i < H + 2; i++){
  	vector<char> vec(W+2, '#');
    
    if(i > 0 && i < H + 1){
    	for (int j = 0; j < W; j++){
        	cin >> vec.at(j+1);
        }
    }
    
    for (int k =0; k < W+2; k++){
    	cout << vec.at(k);
    }
    cout << endl;
  }
  
}






