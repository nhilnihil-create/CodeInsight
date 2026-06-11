#include <iostream>
using namespace std;
const int MOD=1000000007;

int main(){
  int n;
  cin>>n;
  
  long power=1;
  for(int i=1;i<=n;i++){
   power=i*power%MOD; 
  }
  cout<<power<<endl;
  return 0;
}