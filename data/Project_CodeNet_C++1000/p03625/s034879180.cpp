#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n; cin >> n;
  map<long long int, int> mp;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    mp[a]++;
  }
  long long int a = 0, b = 0;
  auto itr = mp.end();
  auto itr2 = itr--;
  for(; ; --itr){
    if(itr->second >= 2){
      if(a == 0){
        a = itr->first;
        itr->second -= 2;
        itr = itr2;
      }
      else{
        b = itr->first;
        cout << a * b << endl;
        return;
      }
    }
    if(itr == mp.begin()){
      cout << 0 << endl;
      return;
    }
  }
  return;
}

int main(){
  solve();
  return 0;
}
