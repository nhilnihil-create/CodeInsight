
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
#include <algorithm>
#include<set>
#include <limits>
#include<iomanip>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007
ll n,a,b;
vector<ll> h;
 bool judge(ll T){
   vector<ll> h2 = h;
   rep(i,n){
     h2[i]=max((ll)0,h2[i]-T*b);
   }
   ll cnt=0;
  rep(i,n){
    cnt+=(h2[i] +a-b-1)/(a-b);
  }
  if(cnt>T){
    return false;
  }else{
    return true;
  }
 }
int main(void){
  cin >> n>>a>>b;
  ll tmp;
  rep(i,n){
    cin>>tmp;
    h.push_back(tmp);
  }
  sort(h.begin(),h.end(),greater<ll>());
  ll tmax=(h[0]+b-1)/b;
  ll tmin=1;
  while(tmax!=tmin){
    if(judge((tmax+tmin)/2)==true){
      tmax=(tmax+tmin)/2;
    }else{
      tmin=(tmax+tmin)/2 +1;
    }
  }
  cout<<tmin<<endl;
  return 0;
}