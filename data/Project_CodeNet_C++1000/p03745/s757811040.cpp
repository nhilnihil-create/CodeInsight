#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++) cin >> v.at(i);
  int c = 1;
  string sorted = "";
  bool continuous = false;
  for(int i = 0; i < N - 1; i++){
    if(!continuous || sorted == ""){
      if(v.at(i) < v.at(i + 1)) sorted = "acs";
      else if(v.at(i) > v.at(i + 1)) sorted = "desc";
      continuous = true;
    }
    if(sorted == "acs" && v.at(i) > v.at(i + 1)){
      c++;
      sorted = "";
      continuous = false;
      continue;
    }
    if(sorted == "desc" && v.at(i) < v.at(i + 1)){
      c++;
      sorted = "";
      continuous = false;
      continue;
    }
  }
  cout << c << endl;
}