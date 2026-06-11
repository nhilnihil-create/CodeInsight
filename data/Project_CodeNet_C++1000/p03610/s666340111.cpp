#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int x,t;
  string s;
  cin >> s;
  rep(i,s.size()){
    if (i%2 == 1) continue;
    else cout << s[i];
  }
  cout << endl;
  
  return 0;
}