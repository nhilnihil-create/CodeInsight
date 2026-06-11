#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  long long d=max(a,max(b,c));
  long long e=min(a,min(b,c));
  long long f=a+b+c-d-e;
  if(d%2==0){
    cout << 0 << endl;
  }
  else{
    cout << e*f << endl;
  }
}
  
