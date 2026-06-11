#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long A[100000];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  if(N<=2){
    cout<<1<<endl;
  }
  else{
  int answer=1;
  int judge=0;
    for(int i=1;i<N;i++){
      if(judge==0){
        if(A[i-1]<A[i]) judge=1;
        if(A[i-1]>A[i]) judge=-1;
      }
      if(judge==1&&A[i-1]>A[i]){
       judge=0;
        answer++;
      }
      if(judge==-1&&A[i-1]<A[i]){
        judge=0;
        answer++;
      }
    }
    cout<<answer<<endl;
  }
  return 0;
}