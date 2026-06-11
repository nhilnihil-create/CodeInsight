#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(a>0){
    cout << "Positive" << endl;
  }
  else if(a<=0 && 0<=b){
    cout << "Zero" << endl;
  }
  else{
    int c=b-a+1;
    if(c%2==0){
      cout << "Positive" << endl;
    }
    else{
      cout << "Negative" << endl;
    }
  }
}
    
