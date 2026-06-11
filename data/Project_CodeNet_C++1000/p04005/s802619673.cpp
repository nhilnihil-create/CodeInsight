#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
const long long INF = 1LL << 60;

int main() {
  long long A, B, C; cin>>A>>B>>C;
  vector<long long> a={A, B, C};
  sort(a.begin(), a.end());
  long long X=a[0];
  long long Y=a[1];
  long long Z=a[2]; //Zが最大
  int x=X%2;
  int y=Y%2;
  int z=Z%2;
  if((x*y*z)%2==0) cout<<0<<endl;
  else cout<<X*Y<<endl;
}
