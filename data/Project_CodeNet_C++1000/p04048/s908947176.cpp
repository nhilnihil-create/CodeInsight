#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n , x, sum=0;
  cin >> n >> x;
  cout<<fixed<<3*(n-__gcd(n,x));
}