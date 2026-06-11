#include <bits/stdc++.h>
using namespace std;
  
int main() {
  string path;
  cin >> path;
  int m = path.size();
  int n=0;
  int s=0;
  int e=0;
  int w=0;
  for(int i=0; i<m; i++) {
    switch(path.at(i)) {
      case 'N':
        n++;
        break;
      case 'S':
        s++;
        break;
      case 'E':
        e++;
        break;
      case 'W':
        w++;
        break;
    }
  }
  if(n>0 && s>0 && e>0 && w>0) {
    cout << "Yes" << endl;
  } else if(n==0 && s==0 && e*w!=0) {
    cout << "Yes" << endl;
  } else if(e==0 && w==0 && n*s!=0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}