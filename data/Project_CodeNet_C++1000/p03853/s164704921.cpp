#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> C(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> C.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    for(int k=0;k<2;k++){
    	for(int j=0;j<W;j++){
      		cout << C.at(i).at(j);
      		if(j==W-1){
            	cout << endl;
      		}
        }    
    }
  }
}
  