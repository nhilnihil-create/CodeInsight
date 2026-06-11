#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;

  int n = s.size();
  char last = s.at(0);
  int ans=0;
  rep(i,n){
    if(s.at(i)!=last){ans++; last=s.at(i);}
  }

  cout << ans;
}