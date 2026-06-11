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

void func(ll *a, ll *b, ll *c){
  ll ah = *a/2;
  ll bh = *b/2;
  ll ch = *c/2;
  *a = bh+ch;
  *b = ah+ch;
  *c = ah+bh;
}

//0->0
//1->1
//2->2
//3->2
//4->3
//5->3
//6->4

int main(){
  string s; cin>>s;
  int N = s.size();
  int r = N+1;
  for(char c='a'; c<='z'; ++c){
    int s_idx=-1;
    int e_idx=-1;
    REP(i,N){ if(s[i]==c){ s_idx=i;break;} }
    REPR(i,N-1){ if(s[i]==c){ e_idx=i;break;} }
    if(s_idx==-1){continue;}
    else{
      int r_c = max(s_idx,N-e_idx-1);
      int dis = 0;
      for(int i=s_idx+1;i<e_idx;++i){
        if(s[i]==c){
          if(dis>0){r_c = max(dis,r_c); dis=0;}
        }
        else{ ++dis; }
      }
      if(dis>0){ r_c = max(dis,r_c); }
      r = min(r_c,r);
    }
  }
  cout << r <<"\n";
}