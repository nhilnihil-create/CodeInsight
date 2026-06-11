#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int K,T;
  cin>>K>>T;
  int answer=0;
  for(int i=0;i<T;i++){
    int a;
    cin>>a;
    answer=max(answer,a*2-K-1);
  }
  cout<<answer<<endl;
  
  return 0;
}