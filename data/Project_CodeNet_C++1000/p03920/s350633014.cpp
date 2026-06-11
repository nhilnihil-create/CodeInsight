#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector <long long> sum(10000009);
  sum[1]=1;
  for(int i=2;sum[i]<=10000000;i++){sum[i]=sum[i-1]+i;}
  int cnt;
  for(int i=2;sum[i]<=10000000;i++){
    if(sum[i]>=N){cnt=i; break;}
  }
  for(int i=cnt;i>=1;i--){
    if(N>=i){N-=i; cout << i << endl;}
    if(N==0){break;}
  }
}