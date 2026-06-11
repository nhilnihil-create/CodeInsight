#include<bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin >> S;
  int A=S.size();
  long long sum=0;
  for(int bit=0;bit<(1<<(A-1));bit++){
    long long sumB=0;
    for(int i=0;i<A-1;i++){
      sumB*=10;
      sumB+=S.at(i)-'0';
      if(bit &(1<<i)){
        sum+=sumB;
        sumB=0;
      }
    }
    sumB*=10;
    sumB+=S.at(A-1)-'0';
    sum+=sumB;
  }
  cout << sum << endl;
}