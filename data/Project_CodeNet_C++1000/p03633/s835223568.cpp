#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  ll L=1;
  cin >> n;
  vector<ll> t(n);
  for(i=0;i<n;i++){
    cin >> t.at(i);
    L=L*(t.at(i)/__gcd(L,t.at(i)));
  }
  cout << L << endl;
}