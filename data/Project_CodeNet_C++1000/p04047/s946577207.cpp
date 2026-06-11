#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,sum=0;
  cin >> n;
  int Arr[2*n];
  for(int x=0;x<2*n;x++){
    cin >> Arr[x];
  }
  sort(Arr,Arr+2*n);
  for(int y=0;y<2*n;y++){
    if(y%2==0){
      sum+=Arr[y];
    }
  }
  cout << sum;
}