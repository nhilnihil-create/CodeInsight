#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int n; 
  cin >> n;
  map<ll, int> mp;
  while(cin >> n){
    if(mp.count(n)){
      mp.erase(n);
    } else {
      mp[n] = 1;
    }
  }
  cout << mp.size() << endl;
}
