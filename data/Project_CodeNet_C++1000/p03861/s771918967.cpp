#include<bits/stdc++.h>
using namespace std;

long long x;

long long func(long long n){
  if(n==-1){
    return 0;
  }
  else{
    return n/x+1;
  }
}

int main(){
  long long a,b;
  cin >> a >> b >> x;
  cout <<(long long)(func(b)-func(a-1)) << endl;
}