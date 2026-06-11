#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

string query(ll n){
  string res;
  printf("? %lld\n",n);
  fflush(stdout);
  cin>>res;
  return res;
}

void answer(ll n){
  printf("! %lld\n", n);
  fflush(stdout);
}

int main(){
	cin.sync_with_stdio(false);
  ll dig=1;
  bool f=true;
  for(ll i=10;i<=1000000000;i*=10){
    if(query(i)=="N"){
      f=false;
      break;
    }
    dig++;
  }
  if(f){
    for(ll i=9;i<=9999999999;i=i*10+9){
      if(query(i)=="Y"){
        answer((i+1)/10);
        return 0;
      }
    }
  }
  string res;
  rep(i,dig){
    if(i==dig-1){
      repl(j,i==0?1:0,10){
        string tmp=res+(char)('0'+j)+"0";
        if(query(stoll(tmp))=="Y"){
          answer(stoll(res+(char)('0'+j)));
          return 0;
        }
      }
    }else{
      ll lb=i==0?1:0,ub=10;
      while(ub-lb>1){
        ll mid=(ub+lb)/2;
        string tmp=res+(char)('0'+mid);
        if(query(stoll(tmp))=="Y")lb=mid;
        else ub=mid;
      }
      res+=(char)('0'+lb);
    }
  }
	return 0;
}
