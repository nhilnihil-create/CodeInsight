#include<bits/stdc++.h>
using namespace std;

int main(){
  long n,a,b;
  cin >> n >> a >> b;
  for(int i=1;i<n;i++){
    long c,d;
    cin >> c >> d;
    long e = max((a+c-1)/c,(b+d-1)/d);
    a = e*c;
    b = e*d;
  }
  cout << a+b << endl;
}