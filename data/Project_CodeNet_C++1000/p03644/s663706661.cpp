#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin>>n;
  int i=1;
  while(1) {
    i*=2;
    if(i>n) {
      cout<<i/2<<endl;
      return 0;
    }
  }
}
