#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
string o,e;
cin >> o >> e;
int n = o.size()+e.size();
string ans(n,'a');
int j = 0;
for(int i = 0; i < n; i+=2){
  ans.at(i) = o.at(j);
  j++;
}
j = 0;
for(int i = 1; i < n; i+=2){
  ans.at(i) = e.at(j);
  j++;
}
cout << ans << endl;
  }
