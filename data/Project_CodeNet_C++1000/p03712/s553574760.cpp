#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  for(int i = 0; i< w+2; i++){
    cout<<"#";
  }
      
  for(int i = 0; i < h; i++){
    cout<<endl<<"#";
    for(int j = 0; j < w; j++){
      vector<char> vec(w);
      cin >> vec.at(j);
      cout<< vec.at(j);
    }
    cout<<"#"<<endl;
  }
      for(int i = 0; i<w+2; i++){
    cout<<"#";
  }
}
