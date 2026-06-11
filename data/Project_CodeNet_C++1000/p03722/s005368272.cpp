#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#include <map>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<int,int>;
const ll M = 1e9+7, mx = 301;
void add(ll& x, ll y) {x+=y; x%=M;}; void mul(ll& x, ll y) {x*=y; x%=M;}; void chmax(ll& x, ll y) {if (x<y) x=y;}; void chmin(ll& x, ll y) {if (x>y) x=y;};

int main() {
  int n,m; cin>>n>>m;
  ll a[m],b[m],c[m];
  for(int i=0;i<m;i++) {
    cin>>a[i]>>b[i]>>c[i];
    a[i]--; b[i]--;
  }

  ll score[n]; fill(score,score+n,-LINF);
  score[0]=0;
  bool update = true;
  bool update_n = false;
  int ii = 0;
  while(update) {
    update = false; update_n = false;
    for(int i=0;i<m;i++) {
      if(score[b[i]]<score[a[i]]+c[i]){
        score[b[i]]=score[a[i]]+c[i];
        update = true;
        if (b[i]==n-1) update_n = true;
      }
    }
    if (ii >= n && update_n) {
      cout<<"inf"<<endl;
      return 0;
    } else if (ii >= 2*n) {
      break;
    }
    ii++;
  }
  cout<<score[n-1]<<endl;
}