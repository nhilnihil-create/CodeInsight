#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  string s;
  for(int i = 0; i < tx - sx; ++i){
    s += 'R';
  }

  for(int i = 0; i < ty - sy; ++i){
    s += 'U';
  }
  
  for(int i = 0; i < tx - sx; ++i){
    s += 'L';
  }
  
  for(int i = 0; i < ty - sy; ++i){
    s += 'D';
  }

  //二巡目
  s += 'D';
  for(int i = 0; i < tx - sx + 1; ++i){
    s += 'R';
  }

  for(int i = 0; i < ty - sy + 1; ++i){
    s += 'U';
  }

  s += 'L';
  s += 'U';
  for(int i = 0; i < tx - sx + 1; ++i){
    s += 'L';
  }
  
  for(int i = 0; i < ty - sy + 1; ++i){
    s += 'D';
  }
  s += 'R';
  cout << s << endl;
}

