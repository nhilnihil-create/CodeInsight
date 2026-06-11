#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=S.size()-1;
  long long sum_all=0;
  for(int bit=0;bit<(1<<A);bit++){
    long long sum=0;
    for(int i=0;i<A;i++){
      int B=S.at(i)-'0';
      sum=10*sum+B;
      if(bit & (1<<i)){
        sum_all+=sum;
        sum=0;
      }
    }
    int B=S.at(A)-'0';
    sum=10*sum+B;
    sum_all+=sum;
  }
  cout << sum_all << endl;
} 