#include <iostream>
#include <vector>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> i_str(h+2);
  string top_last_str(w+2, '#');
  i_str.at(0) = top_last_str;
  for (int i = 0; i < h; ++i){
    string temp;
    cin >> temp;
    temp = "#" + temp + "#";
    i_str.at(i+1) = temp; 
  }
  i_str.at(h + 1) = top_last_str;
  for (int i = 0; i < h + 2; ++i){
    cout << i_str.at(i) << endl;
  }
}