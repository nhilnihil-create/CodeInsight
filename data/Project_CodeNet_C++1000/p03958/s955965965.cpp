#include <iostream>
using namespace std;

int main(){
  int n;
  int sum;
  cin >> sum >> n;
  int max = 0;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    if(max < num) max = num;
  }
  sum -= max;
  if(max-1>sum){
    cout << max-1-sum << endl;
  }else{
    cout << 0 << endl;
  }
  return 0;
}