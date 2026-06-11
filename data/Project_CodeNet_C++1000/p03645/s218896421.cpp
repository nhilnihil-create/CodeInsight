#include<bits/stdc++.h>
using namespace std;


int main(){
  int N , M ; 
  cin >> N >> M ; 
  vector<int> d1(N+1) , d2(N+1);
  for(int i = 0 ; i < M ; i++){
    int a , b ; 
    cin >> a >> b ; 
    if(a == 1) d1.at(b)++ ; 
    if(b == N) d2.at(a)++ ; 
  }
  int cnt = 0 ; 
  for( int i = 0 ; i <= N ; i++){
        cnt++ ; 
    if(d1.at(i) == 0 ) continue ; 

    //cout << cnt << endl ; 
      if( d2.at(i) == 1 ){
        cout << "POSSIBLE" << endl ; 
        return 0 ; 
      } 
    }
  
  
  cout << "IMPOSSIBLE" << endl ; 
}