#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  string ans;
  if(a*b<=0) ans = "Zero";
  else if(a>0 && b>0) ans = "Positive";
  else{
    long long sub = b-a;
    if(sub%2==0) ans = "Negative";
    else ans = "Positive";
  }
  cout << ans << endl;
}