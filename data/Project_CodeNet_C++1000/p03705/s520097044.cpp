#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;

  if(a>b) {cout<<0; return 0;}
  if(a!=b&&n<2) {cout<<0; return 0;}

  ll min, max;
  min = a*(n-1)+b;
  max = a+b*(n-1);

  cout << max-min+1;
}