#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

inline int sign(ll n){
  if(n==0) return 0;
  if(n>0) return 1;
  else return -1;
}

ll adjust(vector<ll> a){
  int n= a.size(), sign0 = sign(a[0]), cur_sign;
  ll acum = a[0], ans = 0, x;
  for(int i= 1; i<n; ++i){
    sign0 *=-1;
    acum+= a[i];
    cur_sign = sign(acum);
    if(cur_sign == sign0){
      continue;
    }else{
      x = sign0 - acum;
      ans+= abs(x);
      a[i] += x;
      acum = sign0;
    }
  }
  return ans;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout<< setprecision(20)<< fixed;
  int n ; cin>> n;
  vector<ll> a(n);
  forn(i,n) cin>> a[i];
  ll ans = 0;
  ll initial_cost = 0;
  if(a[0]>0){
    ans = adjust(a);
    initial_cost = a[0]+1;
    a[0] = -1;
    ans = min(ans, initial_cost + adjust(a));
  }else if(a[0]<0){
    ans = adjust(a);
    initial_cost = -a[0]+1;
    a[0] = 1;
    ans = min(ans,initial_cost+ adjust(a));
  }else{
    a[0]=1;
    ans = 1 + adjust(a);
    a[0]= -1;
    ans = min(ans, 1 + adjust(a));
  }
  cout<< ans<<el;
}


