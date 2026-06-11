#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a.at(i);

  vector<int> rate(9);
  rep(i,n){
    int s =  min(a.at(i)/400, 8);
    rate.at(s)++;
  }

  int fix=0;
  int free=rate.at(8);
  rep(i,8){
    if(rate.at(i))fix++;
  }

  cout << max(fix,1) << " " << fix+free;
}