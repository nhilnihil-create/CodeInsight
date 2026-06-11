#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  int num;
  string line;
  
  cin >> h >> w >> num;
  vector<int> vec(h*w);
  
  int tmpi;
  int cnta = 0;
  for(int i = 1; i <= num; i++){
    cin >> tmpi;
    for(int j = 1; j <= tmpi; j++){
      vec.at(cnta) = i;
      cnta++;
    }
  }

  bool right = true;
  string tmp = "";
  int cnt = w;
  for(int i = 0; i < vec.size();i++){
    if(right == true){
      tmp += to_string(vec.at(i)) + " ";
      cnt--;
      if(cnt == 0){
        cout << tmp.substr(0,tmp.size()-1) << endl;
        tmp = "";
        right = false;
        cnt = w;
      }
    }else{
      tmp = to_string(vec.at(i)) + " " + tmp;
      cnt--;
      if(cnt == 0){
        cout << tmp.substr(0,tmp.size()-1) << endl;
        tmp = "";
        right = true;
        cnt = w;
      }
    }
  }
}
