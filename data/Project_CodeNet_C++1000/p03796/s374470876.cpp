#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin >> N;
  ll p=1;
  ll a=(pow(10,9)+7);
  
  for(ll i=1;i<=N;i++){
    p=p*i;
    p=p%a;
  }
  
  cout << p <<endl;
}

    