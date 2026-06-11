#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) {cin >> a.at(i); a.at(i)--;}

  int count=0;
  int light=0;
  rep(i,n){
    light=a.at(light);
    count++;
    if(light==1){cout<<count; return 0;}
  }

  cout << -1;
}