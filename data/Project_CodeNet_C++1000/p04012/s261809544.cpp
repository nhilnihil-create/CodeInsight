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
   map<char,int> p;
   for(auto e:s)p[e]++;
   bool ans=true;
   for(auto e:s){
      if(p[e]%2!=0) ans=false;
   }
   if(ans)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
}