#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, (b), sizeof(a))
#define fore(i,a) for(int i=0;i<a;i++)
#define fore1(i,j,a) for(int i=j;i<a;i++)
#define print(ar) for(int i=0;i<ar.size();i++)cout<<ar[i]<<" ";
#define END cout<<'\n'
const double pi=acos(-1.0);
 
typedef pair<int, int> PII;
 
typedef vector<long long> VI;
 
typedef vector<string> VS;
 
typedef vector<PII> VII;
 
typedef vector<VI> VVI;
 
typedef map<int,int> MPII;
 
typedef set<int> SETI;
 
typedef multiset<int> MSETI;
 
typedef long int li;
 
typedef unsigned long int uli;
 
typedef long long int ll;
 
typedef unsigned long long int  ull;
ll fastexp (ll a, ll b, ll n) {
  ll res = 1;
  while (b) {
      if (b & 1) res = res*a%n;
      a = a*a%n;
      b >>= 1;
  }
  return res;
}
void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
ll nop(ll m, ll n) 
{ 
   
    ll path = 1; 
    for (ll i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 
  
int main()
 {  fast();
	ll t;
    ll x1,y1,x2,y2;

    char op;
    cin>>x1;
    cin>>op;
    cin>>x2;
    if(op=='+')cout<<x1+x2<<endl;
    else cout<<x1-x2<<endl;
	    
	}