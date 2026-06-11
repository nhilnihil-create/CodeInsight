// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,m,ta,v=0,acc=0,x=0,tmp=0,add=0;
  cin >> n >> m;
  vector<ll> a(n),b(2*m+10,0);
  vector<ll> mp_en[2*m+10];
  map<ll,ll> mp_st;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=1;i<n;i++){
    ta = a[i];
    if(a[i-1]>ta) ta += m;
    add += ta-a[i-1];
    if(ta-a[i-1]!=1){
      mp_st[a[i-1]+2]++;
      mp_en[ta+1].push_back(ta-a[i-1]-1);
    }
  }
  for(int i=1;i<=2*m;i++){
    acc += mp_st[i];
    for(auto j:mp_en[i]){
      acc--;
      x -= j;
    }
    x += acc;
    b[i] = x;
  }
  for(int i=1;i<=m;i++){
    b[i] += b[i+m];
    tmp = max(tmp,b[i]);
  }
  cout << add - tmp<<endl;
}
