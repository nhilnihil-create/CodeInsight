#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう

#define rep(i,n) for(int i=0;i<n;i++)
#define pi       const int pi=3.1415926535
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int n;
  string ans;
  string s;
  string t;
  cin>>n>>s>>t;
  int cnt=0;
  rep(i,n){
    if(s.substr(n-1-i)==t.substr(0,i+1)){
      cnt=i+1;
    }
  }
  ans=s+t.substr(cnt);
  cout<<ans.size();
}