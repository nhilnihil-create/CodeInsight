#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int n;
  cin >> n;
  
  vector<int>num;
  int sum = 0;
  int p = 1;
  
  while(sum < n){
      num.push_back(p);
      sum += p;
      p++;
  }
  
  int s = num.size();
  
  for(int i=0;i<s;i++){
      if(sum - n != num[i])
      cout << num[i] << endl;
  }
  
  return 0;
}