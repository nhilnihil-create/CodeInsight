#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<vector<char>> v(3, vector<char>(0));
  for(int i=0; i<3; i++) {
    cin >> s;
    for(int j=0; j<s.size(); j++) {
      v[i].push_back(s[s.size()-j-1]);
    }
  }
  
  int i = 0;
  while(true) {
    if(i==0) {
      if(v[0][v[0].size()-1]=='a') {
        v[0].pop_back();
        i = 1;
      }
      else if(v[0][v[0].size()-1]=='b') {
        v[0].pop_back();
        i = 2;
      }
      else if(v[0][v[0].size()-1]=='c') {
        v[0].pop_back();
        i = 3;
      }
    }
    
    else if(i==1) { //A
      if(v[0].size()==0) {
        cout << "A" << endl;
        break;
      }
      else if(v[0][v[0].size()-1]=='a') {
        v[0].pop_back();
        i = 1;
      }
      else if(v[0][v[0].size()-1]=='b') {
        v[0].pop_back();
        i = 2;
      }
      else if(v[0][v[0].size()-1]=='c') {
        v[0].pop_back();
        i = 3;
      }
    }
    
    else if(i==2) { //B
      if(v[1].size()==0) {
        cout << "B" << endl;
        break;
      }
      else if(v[1][v[1].size()-1]=='a') {
        v[1].pop_back();
        i = 1;
      }
      else if(v[1][v[1].size()-1]=='b') {
        v[1].pop_back();
        i = 2;
      }
      else if(v[1][v[1].size()-1]=='c') {
        v[1].pop_back();
        i = 3;
      }
    }
    
    else if(i==3) { //C
      if(v[2].size()==0) {
        cout << "C" << endl;
        break;
      }
      else if(v[2][v[2].size()-1]=='a') {
        v[2].pop_back();
        i = 1;
      }
      else if(v[2][v[2].size()-1]=='b') {
        v[2].pop_back();
        i = 2;
      }
      else if(v[2][v[2].size()-1]=='c') {
        v[2].pop_back();
        i = 3;
      }
    }
  }
  return 0;
}