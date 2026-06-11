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
   bool ans=false;
   int num=-1,numa=-1;
   vector<char> v;
   for(auto e:s){
      v.push_back(e);
   }
   if(v.size()==1) {
      cout<<-1<<' '<<-1<<endl;
      return 0;
   }
   rep(i,v.size()-1){
      if(v[i]==v[i+1]){
         num=i;
         ans=true;
         break;
      }
   }
   if(v.size()>2){
   rep(i,v.size()-2){
      if(v[i]==v[i+2]){
         numa=i;
         ans=true;
         break;    
      }
   }
   }
   if(ans&&num>=0) cout<<num+1<<' '<<num+2<<endl;
   else if(ans&&numa>=0) cout<<numa+1<<' '<<numa+3<<endl;
   else cout<<-1<<' '<<-1<<endl;
}