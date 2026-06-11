#include<bits/stdc++.h>
using namespace std;

int main(){
  string A,B,C;
  cin >> A >> B >> C;
  int a=A.size(),b=B.size(),sum=0;
  if(A.at(a-1)==B.at(0)){
    sum++;
  }
  if(B.at(b-1)==C.at(0)){
    sum++;
  }
  if(sum==2){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}