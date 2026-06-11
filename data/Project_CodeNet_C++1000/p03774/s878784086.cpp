#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N , M ;
  cin >> N >> M ;
  vector<int> A(N) ;
  vector <int> B(N) ;
  for ( int i=0 ; i<N ; i++){
    cin >> A[i] >> B[i] ;
  }
   vector<int> C(M) ;
  vector <int> D(M) ;
    for ( int i=0 ; i<M ; i++){
    cin >> C[i] >> D[i] ;
  }
  vector<int64_t> p(N) ;
  vector<int64_t> md(N,4000000000) ;
  
    for ( int i=0 ; i<N ; i++){
    for ( int j=0 ; j<M ; j++){
   if (md[i]>abs(C[j]-A[i])+abs(D[j]-B[i])){
     p[i]=j+1 ;
     md[i]=abs(C[j]-A[i])+abs(D[j]-B[i])  ;
   }
    } 
      cout << p[i] << endl; 
  }

}