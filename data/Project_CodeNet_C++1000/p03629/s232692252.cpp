#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<double> vd;
typedef vector<vd> vdd;

#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define debug_print(x...) cerr << "line " << __LINE__ << " : "; debug_print_in(x);

template <typename First>
void debug_print_in(First first){
  cerr << first << endl;
  return;
}

template <typename First, typename... Rest>
void debug_print_in(First first, Rest... rest){
  cerr << first << " ";
  debug_print_in(rest...);
  return;
}

void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

template <typename First>
void OUT(First first){
  cout << first << endl;
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template<class t, class u> t chmax(t&a,u b){if(a<b)a=b; return a;};
template<class t, class u> t chmin(t&a,u b){if(a>b)a=b; return a;};
int popcount(int t){return __builtin_popcount(t);} //GCC
int popcount(ll t){return __builtin_popcountll(t);} //GCC

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cerr << VEC[i] << " ";
  }
  cerr << endl;
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i,MAT.size()){
    REP(j,MAT[i].size()){
      cerr << MAT[i][j] << " ";
    }
    cerr << endl;
  }
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)((1E+9)+7);

string A1="", A2="";
ll N;
vvll D('z'-'a'+1);
vll dp;

ll dp_init(ll pos, bool flag){
  if(dp[pos]>=0) return dp[pos];
  if(pos>=N) return 0;
  dp[pos] = N;
  if(flag){
    REP(i,'z'-'a'+1){
      auto itr = upper_bound(ALL(D[i]), pos);
      if(itr==D[i].end()){
        dp[pos] = 1;
      }else{
        ll next_pos = *itr;
        chmin(dp[pos], dp_init(next_pos, flag)+1);
      }
    }
  }else{
    REP(i,'z'-'a'+1){
      auto itr = lower_bound(ALL(D[i]), pos);
      if(itr==D[i].begin()){
        dp[pos] = 1;
      }else{
        ll next_pos = *(itr-1);
        chmin(dp[pos], dp_init(next_pos, flag)+1);
      }
    }
  }
  return dp[pos];
}

string solve(string A, bool flag){
  REP(i,'z'-'a'+1) D[i].resize(0);
  REP(i,N) D[A[i]-'a'].pb(i);
  REP(i,N) dp[i] = -1;

  //mat_print(D);

  REP(i,N) dp_init(i, flag);

  debug_print(A);
  //vec_print(dp);

  string ans = "";
  if(flag){
    ll pos = -1;
    while(pos<N){
      ll min_val = N;
      REP(i,'z'-'a'+1){
        auto itr = upper_bound(ALL(D[i]), pos);
        if(itr==D[i].end()){
          return ans;
        }else{
          ll next_pos = *itr;
          chmin(min_val, dp_init(next_pos, flag));
        }
      }
      REP(i,'z'-'a'+1){
        ll next_pos = *upper_bound(ALL(D[i]), pos);
        if(dp_init(next_pos, flag)==min_val){
          ans += i+'a';
          pos = next_pos;
          break;
        }
      }
    }
  }else{
    ll pos = N;
    while(pos>=0){
      ll min_val = N;
      REP(i,'z'-'a'+1){
        auto itr = lower_bound(ALL(D[i]), pos);
        if(itr == D[i].begin()){
          reverse(ALL(ans));
          return ans;
        }else{
          ll next_pos = *(itr-1);
          chmin(min_val, dp_init(next_pos, flag));
        }
      }
      REP(i,'z'-'a'+1){
        ll next_pos = *(lower_bound(ALL(D[i]), pos)-1);
        if(dp_init(next_pos, flag)==min_val){
          ans += i+'a';
          pos = next_pos;
          break;
        }
      }
    }
  }
  return ans;
}

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  string A;
  IN(A);
  A1 += A;
  REP(i,'z'-'a'+1){
    A1 += (char)(i+'a');
    A2 += (char)(i+'a');
  }
  A2 += A;

  N = A1.size();
  dp.resize(N);

  string ans1 = solve(A1, true);
  string ans2 = solve(A2, false);

  debug_print(ans1, ans2);

  OUT(min(ans1, ans2));

  return 0;
}