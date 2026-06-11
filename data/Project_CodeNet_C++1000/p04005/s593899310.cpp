#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   
    long long int N, M, X;
    cin >> N >> M >> X;
  long long int a[3];
  
  a[0] = N;
  a[1] = M;
  a[2] = X;
  
  sort(a,a+3);
  
   if(N%2 == 0 || M%2 == 0 || X%2 == 0){
     cout << "0" << endl;
   }
  
  else{
    cout << a[0]*a[1] << endl;
  }
  
}
