#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

vector<pair<ll, ll>> v;

int main(){
  ll h,w;
  int n;
  cin>>h>>w>>n;
  for(int i=0;i<n;i++){
    ll x,y; cin>>x>>y;
    for(int i=-2;i<=0;i++){
      for(int j=-2;j<=0;j++){
        if(1<=x+i&&x+i<=h-2&&1<=y+j&&y+j<=w-2){
          v.push_back({x+i,y+j});
        }
      }
    }
  }
  sort(v.begin(),v.end());
  ll j[10]={};
  for(int i=0;i<v.size();i++){
    int count=1;
    while(i+1<v.size()&&v[i]==v[i+1]){
      count++;
      i++;
    }
    j[count]++;
  }
  j[0]=(h-2)*(w-2);
  for(int i=1;i<10;i++) j[0]-=j[i];
  for(int i=0;i<10;i++){
    cout<<j[i]<<endl;
  }
  return 0;
}