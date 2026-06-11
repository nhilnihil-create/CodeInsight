#include<bits/stdc++.h>
using namespace std;

int main(){
  string A,B;
  cin >> A;
  cin >> B;
  if(A.size()>B.size()){
    cout << "GREATER" << endl;
  }else if(A.size()<B.size()){
    cout << "LESS" << endl;
  }else{
    for(long long i=0;i<A.size();i++){
      if(A[i]>B[i]){
        cout << "GREATER" << endl;
        return 0;
      }else if(A[i]<B[i]){
        cout << "LESS" << endl;
        return 0;
      }else if(i==A.size()-1){
        cout << "EQUAL" << endl;
        return 0;
      }
    }
  }
  return 0;
}