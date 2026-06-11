#include<bits/stdc++.h>
using namespace std;

int power(int n){
  long long sum = 1;
  for(int i = 1;i <= n;i++){
     sum = sum * i % 1000000007;
  }
  return sum;
}
int main(){
  int n;
  cin >> n;
  cout << power(n) << endl;
}
