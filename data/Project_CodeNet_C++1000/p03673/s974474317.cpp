#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  if(n%2==0){
    for(int i=0;i<n;i++){
      cin >> a.at(i);
      if(i%2==0)
      b.at(n/2+i/2)=a.at(i);
      else
      b.at(n/2-i/2-1)=a.at(i);
    }
  }
  else{
    for(int i=0;i<n;i++){
      cin >> a.at(i);
      if(i%2==0)
      b.at(n/2-i/2)=a.at(i);
      else
      b.at(n/2+i/2+1)=a.at(i);
    }
  }
  for(int i=0;i<n;i++){
    cout << b.at(i) << ' ';
  }
  cout << endl;
}

