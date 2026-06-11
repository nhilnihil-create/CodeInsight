// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
signed main(){
  ll a,b;
  cin >> a >> b;
  if(a%3==0 || b%3==0 || (a+b)%3==0) cout <<"Possible\n";
  else cout <<"Impossible\n";
}
