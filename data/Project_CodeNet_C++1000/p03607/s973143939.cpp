#include<bits/stdc++.h>
using namespace std ;

int main(){
  long long  N ; 
  cin >> N ;
  map<long long , int> mp;
  for(int i = 0 ; i < N ; i++){
    int P ; 
    cin >> P ; 
    mp[P]++ ; 
  }
  int ans = 0 ; 
  for(auto a : mp){
    if(a.second%2 == 1 ) ans++ ; 
    else continue ;
  }
  cout << ans << endl ; 
}