/***
        ***Fresher***
    Md Mahfujur Rahman Khan(So..a;)
    Dept. of CSE
    CSE-28 Batch
    JU-48 Batch
    Jahangirnagar University

    FSTREAM

***/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<functional>
#include<array>
#include<set>
#include<map>
#include<climits>
#include<numeric>
#include<utility>
using namespace std;
/***PAIR***/
#define pll pair<ll,ll>
#define pcl pair<char,ll>
#define psl pair<string, ll>
#define pls pair<ll,string>
#define plc pair<ll, char>
/***MAP***/
#define mll map<ll,ll>
#define msl map<string, ll>
#define mls map<ll, string>
#define mlb map<ll,bool>
#define msb map<string,bool>
#define mcl map<char, ll>
/***VECTOR***/
#define vl vector<ll>
/*** FAST ***/
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/***FUNCTIONS AND MACROS***/
#define IT_ ::iterator
#define F first
#define S second
#define M_P(x, y) make_pair(x, y)
#define PB(v,x) v.push_back(x)
#define PP(x) push(x)
#define RSZ(a , n) a.resize(n)
#define POB pop_back()
#define P_ pop()
#define CL_ clear()
#define LEN(s,cst) (cst)s.length()
#define SZ(s, a) (ll)s.size()
#define CNT(x) count(x)
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define B_ begin()
#define E_ end()
#define F_ front()
#define t_ top()
#define IN(s, a) s.insert(a)
#define ER_  erase
#define GT(x) getline(cin , x)
#define NL_   "\n"
#define SP_ " "
#define R_0 return 0
#define R_ return

#define ul unsigned long long int
#define ll long long int
/***
//bit prime
#define most_prime_loop 1001
#define most_prime_number 1000010
#define prime_MAX_arr 1000010/64 +1
ll PRIME[prime_MAX_arr];
void Set(ll n){ll m= n%64;n/=64;ll x = 1;x <<=m;PRIME[n] |=x;return ;}
bool check(ll n){if(n==2) return true;if(n%2==0) return false;ll m= n%64;n/=64;ll x = 1;x <<=m;return !(x&PRIME[n]);}
void seivee(){fa(x, PRIME)x = 0;Set(2);for(ll i= 3; i <=most_prime_loop; i+=2){if(check(i)){for(ll j = i*i; j <=most_prime_number; j+=i){Set(j);}}}}
***/
#define TEST      ll test; cin >> test; while(test--)

/**template<typename T>inline T POW(T b, T p){T res = 1;while(p){if(p%2)res*=b;b*=b;p/=2;}return res;}**/

#define lcm(a, b) (a/__gcd(a,b))*b
#define INT(dp, v) memset(dp,v, sizeof(dp))
#define all(v) v.B_,v.E_
#define rall(v) v.rbegin(),v.rend()

#define fr(i ,a,  n) for( ll i = a; i <= n; i++)
#define fe(x, n) for( ll i = x; i <= n; i++)
#define fa(x,a)    for(auto &x : a)

#define mod(a) a%1000000007
#define pi acos(-1)


int main()
{
    FAST;
  ll x, a, b;
  cin >> x >> a>> b;
  if(a>=b) cout << "delicious";
  else if(b-a <= x) cout << "safe";
  else cout << "dangerous";
    R_0;
}

