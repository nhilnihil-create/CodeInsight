#include "bits/stdc++.h"
using namespace std;

int checkSign(int A){
    return (int)(A>0)-(int)(A<0);
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  long long sum = 0;
  int sign = 1;
  long long res1 = 0;
  for(int i=0;i<N;i++){
    int tmp = a.at(i);
    if(checkSign(sum+tmp) == 0 || checkSign(sum+tmp) != sign){
      tmp = sign*(abs(sum) + 1);
      res1 += abs(tmp - a.at(i));
    }
    sum += tmp;
    sign *= -1;
  }
  sum = 0;
  sign = -1;
  long long res2 = 0;
  for(int i=0;i<N;i++){
    int tmp = a.at(i);
    if(checkSign(sum+tmp) == 0 || checkSign(sum+tmp) != sign){
      tmp = sign*(abs(sum) + 1);
      res2 += abs(tmp - a.at(i));
    }
    sum += tmp;
    sign *= -1;
  }
  cout << min(res1,res2) << endl;
  return 0;
}