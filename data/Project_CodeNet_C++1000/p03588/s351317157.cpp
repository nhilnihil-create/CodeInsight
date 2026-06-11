#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  long long A,B;
  map<long long, long long> mp;
  for(int i=0;i<N;i++){
    cin >> A >> B;
    mp[A] = B;
  }
  int ans = mp.rbegin()->first;
  for(int i=mp.rbegin()->second -1;i>=0;i--) ans ++;
  cout << ans << endl;
}