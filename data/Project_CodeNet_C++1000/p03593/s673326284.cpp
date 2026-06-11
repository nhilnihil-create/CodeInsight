#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec              vector<int>
#define vecll            vector<ll>
#define vecd             vector<double>
#define vecst            vector<string>
#define vecb             vector<bool>
#define v2(v,n,m,init)   vector<vector<int>>  v(n, vector<int>(m, init))
#define vb2(v,n,m,init)  vector<vector<bool>> v(n, vector<bool>(m, init))
#define vll2(v,n,m,init) vector<vector<ll>>   v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//------------------------------------------------------------------

int main(void){
  int h, w;
  cin >> h >> w;
  arrst(a,h);

  vec s(26, 0);
  rep(i,h){
    rep(j,w){
      s[(a[i][j]-'a')]++;
    }
  }

  rep(i,26){
    s[i] %= 4;
  }

  //prtall(s);

  bool ok=true;
  if(h%2==0 && w%2==0){
    rep(i,26){
      if(s[i]>0) ok=false;
    }
  } else if(h%2==1 && w%2==1){
    bool odd=false;
    int even=0;
    rep(i,26){
      if(s[i]%2==1){
        if(odd){
          ok=false;
        }
        odd=true;
        s[i]--;
      }
      even+=s[i];
    }
    if(even>2*(h/2+w/2)) ok=false;
  } else {
    int mx;
    if(w%2==1){
      mx=h/2;
    } else {
      mx=w/2;
    }
    //prt(mx);
    int even=0;
    rep(i,26){
      if(s[i]%2==1){
        ok=false;
      }
      even+=s[i];
    }
    if(even>mx*2) ok=false;
  }

  prt(ok ? "Yes" : "No");

}
