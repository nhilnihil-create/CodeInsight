#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int N, M;
  cin >> N >> M;
 
  vector<int> a(M);
  vector<int> b(M);
 
  for ( int i = 0; i < M; i++ ){
    cin >> a.at(i) >> b.at(i);
  }
 
  vector<int> d(N);
 
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < M; j++){
       if ( a.at(j) == i + 1 || b.at(j) == i + 1){
         d.at(i) += 1;
       }
    }
   
   cout << d.at(i) << endl;
  }
  
}