#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;

  int count = 0;
  int i;
  vector<bool> list(1e6, false);
  for(i=1; count<n; i++){
    count+=i;
    list[i]=true;
  }

  int diff = count-n;
  for(int j=i; j>0; j--){
    if(j<=diff){
      diff -= j;
      list[j] = false;
    }
    if(diff==0) break;
  }

  for(int j=1; j<i; j++){
    if(list[j]){
      cout << j << endl;
    }
  }
  
  return 0;
}
