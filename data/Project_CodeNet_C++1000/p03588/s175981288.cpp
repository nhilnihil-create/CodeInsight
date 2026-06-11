#include <iostream>
using namespace std;
int main(void){
  int n;
  cin >> n;
  
  int p = 0;
  int q = 0;
  
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    if(a > p){
      p = a;
      q = b;
    }
  }
  
  cout << p + q << endl;
  
  return 0;
}

    