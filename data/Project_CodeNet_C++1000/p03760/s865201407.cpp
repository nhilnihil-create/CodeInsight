#include <bits/stdc++.h>
using namespace std;

int main() {
  string o;
  string e;
  cin >> o >> e;
  
  string s;
  for(int i=0; i<e.size(); i++){
    s += o.at(i);
    s += e.at(i);
  }
  
  if(o.size() != e.size()){
    s += o.at(o.size()-1);
  }
  
  cout << s << endl;
	return 0;
}
