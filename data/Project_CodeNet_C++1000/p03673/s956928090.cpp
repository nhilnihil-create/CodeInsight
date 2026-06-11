#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int n;
  cin >> n;
  vector<int> even;
  vector<int> odd;
  rep(i,n){
    int a;
    cin >> a;
    if(i%2 == 0) odd.push_back(a);
    else even.push_back(a);
  }
  if(n%2 == 0){
    reverse(even.begin(),even.end());
    rep(i,even.size()) cout << even.at(i) << " ";
    rep(i,odd.size()) cout << odd.at(i) << " ";
  }
  else{
    reverse(odd.begin(),odd.end());
    rep(i,odd.size()) cout << odd.at(i) << " ";
    rep(i,even.size()) cout << even.at(i) << " ";
  }
}