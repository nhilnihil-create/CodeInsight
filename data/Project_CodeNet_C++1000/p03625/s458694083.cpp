#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> vec(n);
  rep(i,n){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  int cnt = 1;
  vector<ll> array;
  REP(i,1,n){
    if (vec.at(i) == vec.at(i-1)){
      cnt++;
    }
    else {
      cnt = 1;
    }
    if (cnt == 2){
      array.push_back(vec.at(i));
      cnt = 1;
      i++;
    }
  }
  if (array.size() < 2){
    cout << 0 << endl;
    return 0;
  }
  reverse(array.begin(),array.end());
  cout << array.at(0) * array.at(1) << endl;
  return 0;
}
