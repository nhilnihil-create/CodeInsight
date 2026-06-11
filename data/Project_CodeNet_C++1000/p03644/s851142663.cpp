#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> vec = {1,2,4,8,16,32,64};
  int n;
  cin >> n;
  
  if(n == 1)cout << vec.at(0) << endl;
  else if(2 <= n && n < 4)cout << vec.at(1) << endl;
  else if(4 <= n && n < 8)cout << vec.at(2) << endl;
  else if(8 <= n && n < 16)cout << vec.at(3) << endl;
  else if(16 <= n && n < 32)cout << vec.at(4) << endl;
  else if(32 <= n && n < 64)cout << vec.at(5) << endl;
  else if(64 <= n && n <= 100)cout << vec.at(6) << endl;
}