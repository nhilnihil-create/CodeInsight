
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
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007
int main(void){
  ll n,a,b,c,d;
  cin >> n>>a>>b>>c>>d;
  ll tmp1;
  ll tmp2;
  n--;
  for(ll i=0;i<n+1;i++){
    tmp1=(i-n)*d+i*c;
    tmp2=(i-n)*c+i*d;
    if(tmp1>tmp2)swap(tmp1,tmp2);
    if((ll)abs(b-a)>=tmp1 && (ll)abs(b-a)<=tmp2){
      //cout<<tmp1<<" "<<tmp2<<" "<<i<<endl;
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}