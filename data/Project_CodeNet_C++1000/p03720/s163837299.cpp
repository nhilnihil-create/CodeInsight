#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M ;
    int A[M] ,B[M];
  for ( int i=0 ; i < M ;i++){
    cin >> A[i] >> B[i] ;
  }
  int road[N] ;
  for ( int i=0 ; i<N ; i++ ){
    road[i]=0;
  }
  for ( int i=0 ; i < M ; i++){
    road[A[i]-1]++;
    road[B[i]-1]++;
  }
  for ( int i=0 ; i< N ; i++){
    cout << road[i] << endl;
  }
}