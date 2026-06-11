#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
 
int main() {
int n,m;
cin >> n >> m;
vector<vector<ll>> a(n,vector<ll>(2));
vector<vector<ll>> b(m,vector<ll>(2));
rep(i,n) cin >> a.at(i).at(0) >> a.at(i).at(1);
rep(i,m) cin >> b.at(i).at(0) >> b.at(i).at(1);

rep(i,n){
  ll md = pow(10,18);
  int num;
  rep(j,m){
  ll d = abs(a.at(i).at(0)-b.at(j).at(0))+ abs(a.at(i).at(1)-b.at(j).at(1));
  if(md > d){
    md = d;
    num = j+1;
  }
}
cout << num << endl;
}

}