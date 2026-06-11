#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}


int main(){

  string s,t;
  cin >> s >> t;
  ll q;
  cin >> q;
  vector<ll> sumAs(s.size()+1,0),sumAt(t.size()+1,0);

  FOR(i,0,s.size()){
    sumAs[i+1] = sumAs[i] + ( s[i]=='A' );
  }
  FOR(i,0,t.size()){
    sumAt[i+1] = sumAt[i] + ( t[i]=='A' );
  }

  FOR(i,0,q){

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll numAs = (sumAs[b]-sumAs[a-1]) + 2*((b-a+1)-sumAs[b]+sumAs[a-1]);
    ll numAt = (sumAt[d]-sumAt[c-1]) + 2*((d-c+1)-sumAt[d]+sumAt[c-1]);

    if(numAt%3 == numAs%3){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }

  }


}
