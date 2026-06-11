#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int sum=0;
  int i=0;
  while(sum<n){
    i++;
    sum += i;
  }
  for(int j=1; j<=i; j++){
    if(j==sum-n)continue;
    cout << j << endl;
  }
  return 0;
}
