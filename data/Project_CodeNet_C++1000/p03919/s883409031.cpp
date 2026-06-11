#include <iostream>
#include <map>
using namespace std;

int main(){
  map<int, string> mp;
  for(int i = 0; i < 26; i++){
    mp[i] = i + 65;
  }
  int h, w;
  cin >> h;
  cin >> w;
  string m[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> m[i][j];
    }
  }

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(m[i][j] == "snuke"){
	h = i + 1;
	w = j;
	break;
      }
    }
  }

  cout << mp[w] << h << endl;
  return 0;
}