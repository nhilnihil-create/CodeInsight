#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> p(N);
  for(int i=0; i<N ;i++){
    cin >> p.at(i);
  }
  
  sort(p.begin(),p.end());
  
  int ans = 1;
  
  for(int i=0; i<N-1 ;i++){
    int goukei=1;
    for(int j=1; j<N-i ; j++){
      if(p.at(i)==p.at(i+j) || p.at(i)+1==p.at(i+j) || p.at(i)+2==p.at(i+j)){
        goukei++;
      }
     else if(p.at(i)+2<p.at(i+j)){
       break;
     }
    }
    if(goukei>ans){
      ans = goukei;
    }
    if(ans>N-i){
      break;
    }
  }
  
  cout << ans << endl;    
                       
  
  
  
}