#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
typedef long long ll;
//
int main(){
   string s;
   cin>>s;
   vector<char> ans;
   for(auto e:s){
      if(e=='1') ans.push_back('1');
      else if(e=='0') ans.push_back('0');
      else if(e=='B'&&!ans.empty()) ans.erase(ans.end()-1);
   }
   for(auto e:ans){
   cout<<e;
   }
   cout<<endl;
}