#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long a=1;
  for(long long i=0; i<n; i++){
    long long x;
    cin >> x;
    a=lcm(a,x);
  }
  cout << a << endl;
}