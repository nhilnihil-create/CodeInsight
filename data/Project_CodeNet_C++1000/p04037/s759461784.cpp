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

ll n;
ll a[101010],b[101010];

int main(){
	cin>>n;
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  memcpy(b,a,sizeof(b));
  reverse(a,a+n);
  rep(i,n-1){
    if(a[i+1]<=i+1){
      ll idx=lower_bound(b,b+n,i+1)-b;
      ll w=n-i-idx;
      ll h=a[i]-i;
      if(w%2==0||h%2==0){
        cout<<"First"<<endl;
      }else{
        cout<<"Second"<<endl;
      }
      return 0;
    }
  }
  ll w=1;
  ll h=a[n-1]-n+1;
  if(w%2==0||h%2==0){
    cout<<"First"<<endl;
  }else{
    cout<<"Second"<<endl;
  }
	return 0;
}
