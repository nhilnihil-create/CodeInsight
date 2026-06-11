#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n,k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    if(a[i].second>=k){
      cout << a[i].first << endl;
      break;
    }
    else k-=a[i].second;
  }
}