#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, (b), sizeof(a))
#define fore(i,a) for(int i=0;i<a;i++)
#define fore1(i,j,a) for(int i=j;i<a;i++)
#define print(ar) for(int i=0;i<ar.size();i++)cout<<ar[i]<<" ";
#define END cout<<'\n'
const double pi=acos(-1.0);
 
typedef pair<int, int> PII;
 
typedef vector<long long int> VI;
 
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
const ll N = 1e9+7;



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
int diff(string a,string b){
    int dc=0;
    fore(i,a.length()){
        if(a[i]!=b[i])dc++;
    }
    return dc;
}
int main()
 {  fast();
     ll t,n,k,x,y;
    t=1;
    while(t--){
        cin>>n>>k>>x>>y;
      if(n-k>0)cout<<(n-k)*y+k*x<<endl;
      else cout<<n*x<<endl;
    }
	}
