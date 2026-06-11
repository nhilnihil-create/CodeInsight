#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define N 100005
constexpr ll inf = 100000000000000;
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/

bool check(int mid){

  return false;
}

ll serch(ll ok,ll ng) {
	while (abs(ok-ng) > 1) {
		ll mid = (ok + ng) / 2;
		if (check(mid))ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(){
  cout<<fixed<<setprecision(20);
  cin.tie(0);ios::sync_with_stdio(false);
  ll n,l,t;
  cin>>n>>l>>t;
  ll a[n],x[n];
  rep(i,n){
    cin>>a[i]>>x[i];
  }
  ll pos1=0,pos2=0,tmp=0;
  if(x[0]==1){
    rep(i,n){
      if(x[i]!=x[0]){
        ll dist=a[i]-a[0],col=0;
        if(2*t-dist>=0){
          col=(2*t-dist)/l+1;
          pos1=((pos1+col)%n+n)%n;
        }
      }
    }
  }else{
    rep(i,n){
      if(x[i]!=x[0]){
        ll dist=a[0]+l-a[i],col=0;
        if(2*t-dist>=0){
          col=(2*t-dist)/l+1;
          pos1=((pos1-col)%n+n)%n;
        }
      }
    }
  }
  rep(i,n){
    if(x[i]==1){
      a[i]=(a[i]+t)%l;
    }else{
      a[i]=((a[i]-t)%l+l)%l;
    }
  }
  tmp=a[0];
  sort(a,a+n);
  if(x[0]==1){
    repr(i,n){
      if(a[i]==tmp){
        pos2=i;
        break;
      }
    }
  }else{
    rep(i,n){
      if(a[i]==tmp){
        pos2=i;
        break;
      }
    }
  }
  rep(i,n){
    cout<<a[(i+pos2-pos1+n)%n]<<endl;
  }
  return 0;
}

