#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if((a&1)|(b&1)|(c&1)){
    cout << 0 << endl;
    return 0;
  }
  if(a==b && b==c){
    cout << -1 << endl;
    return 0;
  }
  for(int i=1;;i++){
    int ha=a/2;
    int hb=b/2;
    int hc=c/2;
    a=hb+hc;
    b=ha+hc;
    c=ha+hb;
    if((a&1)|(b&1)|(c&1)){
      cout << i << endl;
      return 0;
    }
  }
}

