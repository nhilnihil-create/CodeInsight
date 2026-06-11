#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
  ll q,h,s,d,n;
  cin >> q >> h >> s >> d >> n;
  if(h>q*2)h=q*2;
  if(s>h*2)s=h*2;
  if(d>s*2)d=s*2;
  cout << n/2*d+n%2*s;
}