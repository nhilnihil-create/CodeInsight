#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
 long long int a;
    
  cin >> a;
  
  for(int i=0;i<100000;i++){
    
    if(i*(i+1) >=2*a){
      
      cout << i << endl;
      
      return 0;
    }
  }
}

      