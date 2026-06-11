#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> x(3);
  int five = 0, seven = 0;
  for(int i = 0; i < 3; i++){
    cin >> x.at(i);
    if(x.at(i) == 5) five++;
    if(x.at(i) == 7) seven++;
  }
  
  if(five == 2 && seven == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}

