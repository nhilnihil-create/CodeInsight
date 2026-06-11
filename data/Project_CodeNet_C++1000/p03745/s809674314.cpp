#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (int)x.size()
#define SP(x)  setprecision((int)x)


using namespace std ;
typedef long long ll;
using Graph = vector<vector<int>>;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

//-------------------------------------------------
// 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}


//-------------------------------------------------
// メモ
/*






*/
//-------------------------------------------------


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n ;
  cin >> n ;
  vint num(n) ;
  int ans = 0 ;
  REP(i,n){
    cin >> num[i] ;
  }
  queue<char> Q ;
  REP(i,n-1){
    if(num[i]<num[i+1]){
      Q.push('+') ;
    }
    else if(num[i]>num[i+1]){
      Q.push('-') ;
    }
    else{
      Q.push('0') ;
    }
  }
  
  char a = '0' ;
  while(!Q.empty()){
    char c = Q.front() ;
    Q.pop() ;
    if(c=='+'){
      if(a=='0' || a=='+'){
        a = '+' ;
      }
      else{
        a = '0' ;
        ans++ ;
      }
    }
    if(c=='-'){
      if(a=='0' || a=='-'){
        a = '-' ;
      }
      else{
        a = '0' ;
        ans++ ;
      }
    }
  }
  
  cout << ans+1 <<endl ;
    
  
      
  
  
  
  return 0 ;
}

