#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,maxcount=-1,P=0;
  cin >> N;
  for(int i=0;i<N;i++){
    int A=i+1,count=0;
    while(A%2==0){
      count++;
      A/=2;
    }
    if(maxcount<count){
      maxcount=count;
      P=i+1;
    }
  }
  cout << P << endl;
}
      