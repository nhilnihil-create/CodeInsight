#include <iostream>
using namespace std;

int N;
int A[110];
int B[110];
int C[110];

int main(){
   int i=0;
   cin >> N ;
   for (i=0; i<N; i++) A[i]=i+1;
   for (i=0; i<N; i++) C[i]=i+1;
  
for(i=0;i<N;i++){
   B[i]=0;
  
   while(A[i]%2==0){  
    A[i]/=2; 
    B[i]=B[i]+1;
    }
}//ここまでで2で割れる回数は計算できている

 
  int high=B[0];
  int answer=C[0];
  
  for(i=0;i<N;i++){
  if (i==N-1) break ;
  else if(high<B[i+1]) {
    high=B[i+1];
    answer=C[i+1] ;
  }
  }
  cout << answer << endl;
}