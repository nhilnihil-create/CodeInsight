#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a,b;
  cin>>a>>b;
  if(a<0&&b<0){
    if((b-a+1)%2)cout<<"Negative"<<endl;
    else cout<<"Positive"<<endl;
  }
  else if(a<=0&&0<=b)cout<<"Zero"<<endl;
  else if(0<a&&0<b)cout<<"Positive"<<endl;

  return 0;
}
