#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, p;
  cin >> n >> p;
  vector<long long> vec(5001, 0);
  vec[0] = 1;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    for(int j=5000; j>=0; j--){
      if(vec[j] != 0 && j+num <= 5000) vec[j+num] += vec[j];
    }
  }
  long long sum = 0;
  if(p == 0){
    for(int i=0; i<=5000; i++){
      if(i%2==0) sum += vec[i];
    }
  }else{
    for(int i=0; i<=5000; i++){
      if(i%2==1) sum += vec[i];
    }
  }
  cout << sum << endl;
  return 0;
}
