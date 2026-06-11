#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp std::make_pair
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
ll N,A,B,C,D;
int main(){
  cin>>N>>A>>B>>C>>D;
  ll max=A+(N-1)*D;
  ll mod=C+D;
  ll x=max%mod;
  ll y=(D-C)*(N-1);
  ll z=B%mod;
  bool f;
  if(B>max) f=false;
  else{
    if(x>=y){
      if(x-y<=z&&z<=x) f=true;
      else f=false;
    }
    else{
      if((0<=z&&z<=x)||(mod-y+x<=z&&z<=mod)) f=true;
      else f=false;
    }
  }
  if(f) prin("YES");
  else prin("NO");
  return 0;
}
