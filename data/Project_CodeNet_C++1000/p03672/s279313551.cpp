#include<bits/stdc++.h>
// Useful constants
#define INF  (int)1e9
#define EPS   1e-9
#define MOD 1000000007ll
#define PI 3.14159
// for input-output
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// iteration macros: have advantage of auto-casting and not recomputing arguments
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
// input macro
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}
//output macro
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
// shortcut for data type
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define uset unordered_set
#define umap unordered_map
//--namespace
using namespace std;
//--useful function
ll gcd(ll a, ll b){ll temp;while (b > 0){temp = a%b;a = b;b = temp;} return a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
// --clock funtion
clock_t time_p=clock();
void TimeTaken()
{
    time_p=clock()-time_p;
    cerr<<"Completion time : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
// --solve function
void solve() {

}
bool even(string s){
	int flag=0,n=s.length();
	REP(i,0,(n/2)-1){
		if(s[i]!=s[i+(n/2)]){
			flag=1;
			break;
		}
	}
	if(flag==1)
		return false;
	else
		return true;
}


//--main function
int main(){
	string s;cin>>s;s.pop_back();
	int sol=1;
	while(s.length()%2!=0 || !even(s)){
		s.pop_back();	
	}
	cout<<s.length();
	return 0;

//   TimeTaken();
}

