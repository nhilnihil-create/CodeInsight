#include <bits/stdc++.h>
using namespace std;

int main(){
  int N=7;
  vector<long int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  int c=0;
  if(A.at(0)%2==1){
    c += 1;
  }
  if(A.at(3)%2==1){
    c += 1;
  }
  if(A.at(4)%2==1){
    c += 1;
  }
  
  long int ans =0;
  ans = A.at(1)+A.at(0)+A.at(3)+A.at(4);
if(c != 3){
  long int res =0;
  ans = ans - c;
  if((A.at(0)>0)&&(A.at(3)>0)&&(A.at(4)>0)){
  res = A.at(1)+2*((A.at(0)-1)/2+(A.at(3)-1)/2+(A.at(4)-1)/2)+3;
  if(res > ans){
  ans = res;
  }
  }
}
  cout << ans << endl;
}
