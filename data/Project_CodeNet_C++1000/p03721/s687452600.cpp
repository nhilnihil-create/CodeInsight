#include<bits/stdc++.h>
using namespace std ;

int main(){
  long long N , K ; 
  cin >> N >> K ; 
  vector<int> a(N) , b(N) ; 
  for(int i = 0 ; i < N ; i++) cin >> a.at(i) >> b.at(i) ; 
  
  long long cnt = 0 ; 
  long long ans = 0 ; 
  vector<pair<int , int>> ab(N) ; 
  
  for(int i = 0 ; i < N ; i++){
    ab.at(i) = make_pair(a.at(i) , b.at(i)) ; 
  }
  sort(ab.begin() , ab.end()) ; 
  for(auto p : ab){
    cnt += p.second ; 
    ans =  p.first ; 
    if(cnt >= K){
      cout << ans << endl;
      return 0 ; 
    }
  }
}