//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

//end of jonathanirvings' template v3.0.3 (BETA)

vi solve(LL x, int mulai)
{
  vi res = {};
  if (x == 0) return res;
  if (x % 2 == 1)
  {
    vi temp = solve(x/2,mulai+1);
    // res.pb(mulai);
    res.pb(mulai);
    REP(i,SIZE(temp)/2) res.pb(temp[i]);
    res.pb(mulai);
    REP(i,SIZE(temp)/2) res.pb(temp[i+SIZE(temp)/2]);
    // REP(i,SIZE(temp)) res.pb(temp[i]);
    // REP(i,SIZE(temp)) res.pb(temp[i]);
    // res.pb(mulai);
  } else 
  {
    vi temp = solve((x-1),mulai+1);
    res.pb(mulai);
    REP(i,SIZE(temp)) res.pb(temp[i]);
    // res.pb(mulai+1);
    // REP(i,SIZE(temp)/2) res.pb(temp[i]);
    // res.pb(mulai+1);
    // REP(i,SIZE(temp)/2) res.pb(temp[i+SIZE(temp)/2]);
    res.pb(mulai);
  }
  return res;
}

LL n;
vi risan;

void print()
{
  printf("%d\n",SIZE(risan));
  printf("%d",risan[0]);
  FOR(i,1,SIZE(risan)) printf(" %d",risan[i]);
  puts("");
}

void cek()
{
  REP(bit,1<<SIZE(risan))
  {
    if (bit == 0) continue;
    if (__builtin_popcount(bit) % 2 == 1) continue;
    vi ix;
    REP(i,SIZE(risan)) if(bit & (1 << i)) ix.pb(i);
    // if (ix == vector<int>{2, 3, 5, 6}) VALUE(bit);
    // VALUE(risan[2]);
    // VALUE(risan[5]);
    // VALUE(risan[3]);
    // VALUE(risan[6]);
    REP(i,SIZE(ix)/2) if(risan[ix[i]] != risan[ix[i+SIZE(ix)/2]]) goto hell;
    REP(i,SIZE(ix)) debug("%d ",risan[ix[i]]); debug("\n");
    hell:;
  }
}

int main()
{
  scanf("%lld",&n);
  risan = solve(n,1);
  print();
  // LL x = 1e12;
  // FORN(i,1,10000)
  // {
  //   if (SIZE(solve(x-i,1)) > 200)
  //   {
  //     VALUE(x-i);
  //   }
  // }
  // cek();
  // ++n;
  // FORD(i,60,0)
  // {
  //   LL x = (1LL << i);
  //   if (n >= x)
  //   {
  //     int y = i + 1;
  //     REP(i,y) risan.pb(lst);
  //     ++lst;
  //     n -= x;
  //   }
  // }
  // printf("%d\n",SIZE(risan));
  // printf("%d",risan[0]);
  // FOR(i,1,SIZE(risan)) printf(" %d",risan[i]);
  // puts("");
  return 0;
}










