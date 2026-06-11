#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
   int n;
   cin>>n;
   string s,t;
   cin>>s>>t;
   string S=s,T=t;
   int ans=0;
   rep(i,n+1){
       bool flag=true;
       s+=t.substr(i);
       rep(k,n){
if(t[k]!=s[s.size()-n+k]) flag=false;
       }
       if(flag){
ans=s.size();
       }
       //cout<<s<<endl;
       s=S;
   }
   cout<<ans<<endl;
    return 0;
}
