#include <bits/stdc++.h>
using namespace std;

int main(){
  map<long long,bool> mp;
  long long N;
  cin >> N;
  long long ans = 0;
  for(long long i=0; i<N; i++){
    long long A;
    cin >> A;
    if(mp[A] == false){
      mp[A] = true;
    }
    else{
      mp[A] = false;
    }
    if(mp[A] == true){
      ans++;
    }
    else{
      ans--;
    }
  }
  cout << ans << endl;
}
