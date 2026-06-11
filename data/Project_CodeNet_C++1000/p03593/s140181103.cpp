#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int h, w, i, j;
  int d, q;
  char c;
  bool b = 0;
  vector<int> alp;
  string buff;

  cin >> h >> w;
  q = (h/2) * (w/2);
  d = (h*w-4*q) / 2;

  alp.resize('z'-'a'+1,0);

  for(i=0;i<h;i++){
    cin >> buff;
    for(j=0;j<w;j++){
      ++alp[buff[j]-'a'];
    }
  }

  for(i=0;i<'z'-'a'+1;i++){
    q -= alp[i] / 4;
    alp[i] -= (alp[i]/4) * 4;

    d -= alp[i] / 2;
    alp[i] -= (alp[i]/2) * 2;

    if(alp[i]==1){
      if(b){
        cout << "No" << endl;
        return 0;
      }
      b=1;
    }
  }
  
  if(q>0){
    cout << "No" << endl;
    return 0;
  }
  else{
    cout << "Yes" << endl;
    return 0;
  }

  return 0;
}
