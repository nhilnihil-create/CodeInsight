#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(int a,int b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(int a,int b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
  string s;
  cin>>s;
  vector<char> t;
  rep(i,len(s)){
    if(s[i]!='B'){
      t.push_back(s[i]);
    }
    if(s[i]=='B'){
      if(t.size()>0){
        t.pop_back();
      }
      if(t.size()==0) continue;
    }
  }
  rep(i,t.size()){
    cout<<t[i];
  }
  cout<<endl;
}