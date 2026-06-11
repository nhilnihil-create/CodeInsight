#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

int main(){
  ll X,Y;
  cin>>X>>Y;
  if(abs(X-Y)<=1) cout<<"Brown"<<endl;
  else cout<<"Alice"<<endl;
  return 0;
}
