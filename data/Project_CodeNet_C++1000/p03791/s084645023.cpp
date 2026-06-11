#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  vector<int> data;

  cin>>N;
  for (int i=0;i<N;i++){
    int d;
    cin>>d;
    data.push_back(d);
  }

  long long int ans = 1;
  long long int num = 2;
  long long int del = 0;
  for (int i=1;i<N;){
    int xi=data[i];
    
    if ((2*num-1)>xi) {
      ans *= (num);
      ans %= 1000000007;
      num --;
      del ++;
    } else {
      i++;
      num ++;
    }
    
  }

  for(int i=N-del;i>1;i--){
      ans *= i;
      ans %= 1000000007;
  }
  cout << ans << endl;
  
  return 0;
}
