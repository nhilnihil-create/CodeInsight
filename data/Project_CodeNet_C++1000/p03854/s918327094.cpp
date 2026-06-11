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
   string s;cin>>s;
   reverse(all(s));
   string a="dream",b="dreamer",c="erase",d="eraser";
   reverse(all(a));
   reverse(all(b));
   reverse(all(c));
   reverse(all(d));
   bool ans=true;
//   cout<<s<<endl;
   rep(i,s.size()){
      if(s.substr(i,6)=="resare")i+=5;
      else if(s.substr(i,5)=="esare")i+=4;
      else if(s.substr(i,7)=="remaerd")i+=6;
      else if(s.substr(i,5)=="maerd")i+=4;
      else ans=false;
//      cout<<i<<endl;
   }
   if(ans)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}
