#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   string s,t;
  cin >> s;
  t=s.substr(0,4);
  s=s.substr(4,8);
  cout << t+" "+s << endl;
  
  return 0;
}

