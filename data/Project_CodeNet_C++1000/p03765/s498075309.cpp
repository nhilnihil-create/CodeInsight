#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;


signed main() {
 string s,t;
 cin>>s>>t;
 int p[s.size()],q[t.size()];
 if(s[0]=='A')p[0]=1;
 else p[0]=2;
 for(int i=1;i<s.size();i++){
   if(s[i]=='A')p[i]=p[i-1]+1;
   else p[i]=p[i-1]+2;
 }
 if(t[0]=='A')q[0]=1;
 else q[0]=2;
 for(int i=1;i<t.size();i++){
   if(t[i]=='A')q[i]=q[i-1]+1;
   else q[i]=q[i-1]+2;
 }
int Q,a,b,c,d,x,y;
cin>>Q;
for(int i=0;i<Q;i++){
  cin>>a>>b>>c>>d;
  x=p[b-1];
  if(a>1)x-=p[a-2];
  y=q[d-1];
  if(c>1)y-=q[c-2];
  //cerr<<x<<' '<<y;
  if(x%3==y%3)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
return 0;
}
