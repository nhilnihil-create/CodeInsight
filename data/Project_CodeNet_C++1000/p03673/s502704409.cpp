#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  int i=n-1;
  if(n%2==0){
    while(i>0){cout << a.at(i) << " "; i-=2;}
    i=0;
    while(i<n){cout << a.at(i) << " "; i+=2;}
  }else{
    while(i>=0){cout << a.at(i) << " "; i-=2;}
    i=1;
    while(i<n){cout << a.at(i) << " "; i+=2;}
  }
}