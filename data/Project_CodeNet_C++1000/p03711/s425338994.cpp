#include <bits/stdc++.h>
using namespace std;

int main(void){
   
  int x,y;
  int A[] = {1,3,5,7,8,10,12};
  int B[] = {4,6,9,10};
  int C[] = {2};
  
  cin >> x >> y;
  if( find(begin(A),end(A), x) != end(A) &&  find(begin(A),end(A), y) != end(A) ){
      cout << "Yes" <<endl;
  }
  else if(find(begin(B),end(B), x) != end(B) &&  find(begin(B),end(B), y) != end(B)){
cout << "Yes" <<endl;
  }
  else if(find(begin(C),end(C), x) != end(C) &&  find(begin(C),end(C), y) != end(C)){
cout << "Yes" <<endl;
  }
  else{
      cout << "No" <<endl;
  }
}