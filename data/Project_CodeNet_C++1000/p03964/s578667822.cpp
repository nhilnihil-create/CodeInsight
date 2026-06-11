#include<bits/stdc++.h>
using namespace std;
#define long long long

int main(){
  int N;
  cin >> N;
  long a=1, b=1;
  for(int i=1; i<=N; i++){
    long x, y; cin >> x >> y;
    long n = max((a+x-1)/x,(b+y-1)/y);
    a = n*x;
    b = n*y;
  }
  cout << a+b << endl;
  return 0;
}