#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
int n;
cin >> n;
map<int,int> mp;
rep(i,n){
  int a;
  cin >> a;
  mp[a]++;
}
int cnt  = 0;
for(auto itr = mp.begin(); itr != mp.end(); itr++){
  int x = itr->second;
  if(x%2!=0)cnt++;
}
cout << cnt << endl;
}