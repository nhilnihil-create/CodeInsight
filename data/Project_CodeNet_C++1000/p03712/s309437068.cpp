#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int h, w;
  vector<string> str(101);
  
  cin >> h >> w;
  
  rep(i, h)
    cin >> str.at(i);
  
  rep(i, w + 2)
    cout << "#";
  cout << endl;
  
 rep(i, h){
   cout << "#" << str.at(i) << "#" << endl;
 }
   
  
  rep(i, w + 2)
    cout << "#";
  cout << endl;

}
