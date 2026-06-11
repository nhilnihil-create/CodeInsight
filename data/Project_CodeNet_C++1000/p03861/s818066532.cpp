#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,x;
  cin >> a >> b >> x;
  cout << b/x-(a-x)/x-(bool)(a>x&&a%x!=0) << endl;
}