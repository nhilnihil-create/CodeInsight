#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main(){
  long N,tmp,minsub;
  long Min = 2000000009;
  cin >> N;
  vector<long> sum;
  
  for(int i=0;i<N;++i){
    cin >> tmp;
    if(i==0){
      sum.push_back(tmp);
    }else{
      sum.push_back(sum[i-1]+tmp);
    }
  }

  for(int i=0;i<N-1;++i){
    minsub = abs(sum[N-1]-sum[i]-sum[i]);
    if(Min > minsub){
      Min = minsub;
    }
  }

  cout << Min << endl;
}
