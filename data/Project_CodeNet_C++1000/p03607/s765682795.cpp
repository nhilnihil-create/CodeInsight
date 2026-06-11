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

  sort(a.begin(), a.end());
  int ans=0;
  a.push_back(0);
  
  rep(i,n){
    int count=0;
    
    while(a.at(i)==a.at(i+1)){
      i++;
      count++;
    }

    if(count%2==0) ans++;
  }

  cout << ans;
}