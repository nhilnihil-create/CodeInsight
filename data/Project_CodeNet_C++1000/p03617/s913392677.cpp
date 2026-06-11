#include<bits/stdc++.h>
using namespace std;

int main(){
  long long q,h,s,d,n;
  cin >> q >> h >> s >> d >> n;
  long long ans = 0;
  long long one = min(2 * q, h);
  long long l = min(2 * one, s);
  if(d >= 2 * l){
    cout << n * l << endl;
  }else{
    cout << (n / 2) * d + (n % 2) * l << endl;
  }
}