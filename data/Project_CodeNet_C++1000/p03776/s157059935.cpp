#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

ll c[51][51];
void cal_c(ll N){
  for(int i=0;i<=N;++i){
    for(int j=0;j<=i;++j){
      if(j==0){ c[i][j] = 1;}
      else if(j==i){ c[i][j] = 1;}
      else{ c[i][j] = c[i-1][j-1]+c[i-1][j];  }
    }
  }
}
ll func(ll x,ll y){ return c[x][y];}

int main(){
  ll N,A,B; cin>>N>>A>>B;
  cal_c(N);
  ld v[N]; CINA(v,N);
  sort(v,v+N,greater<ll>());
  
  ld avr_max = 0; REP(i,A){ avr_max+=v[i];} avr_max /= A;
  
  ll a_count = 0,p_a=0;
  REP(i,N){
    if(v[i]==v[A-1]){
      ++a_count;
      if(i<A){ ++p_a;}
    }
  }
  ll p=0LL;
  if(p_a==A){
    for(p_a=A;p_a<=B;++p_a){
      p += c[a_count][p_a];
    }
  }else{
    p += c[a_count][p_a];
  }
  
  cout << fixed << setprecision(7) << avr_max <<"\n";
  cout << p << "\n";
}