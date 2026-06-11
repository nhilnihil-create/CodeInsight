#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  int A=1;
  int M=0;
  for(int i=1;i<=N;i++){
    int a=0;
    int j=i;
    while(j%2==0){
      a++;
      j/=2;
    }
    if(M<a){
      M=a;
      A=i;
    }
  }
  cout<<A<<endl;
}