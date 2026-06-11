 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}
ll ketawa(ll a){ll r=0;while(a){r+=a%10;a/=10;}return r;}

 
int main(){

  ll N,M;
  cin >> N >> M;
  map<ll,ll> X;
  vector<ll> cnt(100001,0);
  vector<ll> can_make(100001,0);

  for(int i=0; i<N; i++){
    ll x;
    cin >> x;
    X[x]++;
    can_make[x%M] -= (X[x]-1) / 2;
    can_make[x%M] += X[x] / 2;
    cnt[x%M]++;
  }

  ll ans = 0;
  for(int i=0; i<M; i++){
    int j = M - i;
    if(j<i)continue;
    if(j==M){
      ans += cnt[0]/2;
      continue;
    }else if(j==i && j+i==M){
      ans += cnt[i]/2;
      continue;
    }

    if(cnt[i] < cnt[j]){
      ans += cnt[i];
      ans += min(can_make[j],(cnt[j]-cnt[i])/2);
    }else{
      ans += cnt[j];
      ans += min(can_make[i],(cnt[i]-cnt[j])/2);
    }
  }

  cout << ans << endl;
}
