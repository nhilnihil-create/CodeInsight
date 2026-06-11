#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<pair<int,int>> vec;
  rep(i,n){
    int a, b;
    cin >> a >> b;
    vec.push_back(make_pair(a,b));
  }
  sort(vec.begin(),vec.end());

  ll cnt = 0;
  for (pair<int,int> p: vec){
    int a, b;
    tie(a,b) = p;
    cnt += b;
    if (cnt >= k){
      cout << a << endl;
      return 0;
    }
  }
}
