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


bool no_need(vector<int> &a,int n,int k,int i){
  const int S = 5010;
  bitset<S> bits;
  bits[0] = 1;
  FOR(j,0,n){
    if(j==i)continue;
    if(k < a[j])break;
    bits = bits<<a[j] | bits;
  }
  int first=MOD;
  FOR(j,max(0,k-a[i]),k){
    if(bits[j]){
      first = j;
      break;
    }
  }
  if(first==MOD)return true;
  return false;
}

 
int main(){

  int N,K;
  cin >> N >> K;

  vector<int> a(N);
  for(auto &&x:a)cin>>x;
  SORT(a);
  
  int l=-1,r=N;

  while(r-l>1){
    int mid = (r+l)/2;
    if(no_need(a,N,K,mid)){
      l = mid;
    }else{
      r = mid;
    }
  }

  cout << l+1 << endl;
}

/*
  任意 -> すべて

  a[i]を含む集合Siで
  K<= sum(Si) < K+a[i]
  のものがあればa[i]は必要

  a[j] > a[i] について
  先ほどのSiにa[j]が含まれていればa[j]は必要
  Siにa[j]が含まれていなくてもa[i]と交換することでa[j]は必要とわかる


  a[i]が不必要　-> K<=sum(S)<K+a[i] となるa[i]を含む集合Sがない
  
  a[j] < a[i]について
  if(a[j] in S){
    K+a[j] < K+a[i]より
    K<=sum(S)<K+a[j] もない
  }else{
    K <= sum(S) < K+a[i] がない
    K-a[i]+a[j] <= sum(S)-a[i]+a[j] < K+a[j]　もない
    K <= sum(S') < K+a[j]　もない
  }
*/
