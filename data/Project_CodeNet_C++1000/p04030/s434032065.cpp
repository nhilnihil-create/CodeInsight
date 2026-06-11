#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;
  
  vector<char>ans;
  rep(i,s.length()){
    char now = s.at(i);
    if(now=='0') ans.push_back('0');
    if(now=='1') ans.push_back('1');
    if(now=='B'&&ans.size()) ans.pop_back();
  }

  rep(i, ans.size())cout << ans.at(i);
}