#include<iostream>
using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  if(a*b<=0){
    cout <<  "Zero";
  }else{
    if(a>0){
      cout << "Positive";
    }else if((b-a)%2==0){
      cout << "Negative"; 
    }else{
      cout << "Positive";
    }
  }
}