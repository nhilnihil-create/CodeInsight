#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  int c = 0;
  if(a.size() > b.size()) cout << "GREATER" << endl;
  else if(a.size() < b.size()) cout << "LESS" << endl;
  else{
    for(int i=0; i<a.size(); i++){
      if((int)a[i] > (int)b[i]){
        c++;
        break;
      }
      if((int)a[i] < (int)b[i]){
        c--;
        break;
      }
    }
    
    if(c == 1) cout << "GREATER" << endl;
    if(c == -1) cout << "LESS" << endl;
    if(c == 0) cout << "EQUAL" << endl;
  }
	return 0;
}
