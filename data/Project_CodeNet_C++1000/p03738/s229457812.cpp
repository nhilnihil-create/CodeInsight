#include<iostream>
#include<string>
using namespace std;

int main(){
  string A;
  string B;
  cin >> A;
  cin >> B;
  
  if(A.size() > B.size())
    cout << "GREATER";
  if(A.size() < B.size())
    cout << "LESS";
  if(A.size() == B.size()){
    for(int i=0;i<A.size();i++){
      if(A[i]>B[i]){
        cout << "GREATER";
        return 0;
      }
      else if(A[i]<B[i]){
        cout << "LESS";
        return 0;
      }
    }
    cout << "EQUAL";
  }
  return 0;
}