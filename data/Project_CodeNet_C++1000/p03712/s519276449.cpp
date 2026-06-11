#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> str(H,vector<char>(W));
  for(int i=0;i<H;i++){
  	for(int j=0;j<W;j++){
    	cin >> str.at(i).at(j);
    }
  }
  for(int i=0;i<H+2;i++){
  	for(int j=0;j<W+2;j++){
    	if(i==0||i==H+1||j==0||j==W+1) cout << '#';
      	else cout << str.at(i-1).at(j-1);
    }
    cout << endl;
  }
}