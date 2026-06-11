#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;
  int a = 0;
  int z = 0;
  bool once = true;
  for (int i = 0; i < s.size(); i++){
    if(once){
      if (s.at(i) == 'A'){
      	a = i;
        once = false;
    	}
    }
  }
  for (int i = 0; i < s.size(); i++){
    if (s.at(i) == 'Z'){
      	z = i;
    	}
  }
  cout << z-a +1 << endl;
}

