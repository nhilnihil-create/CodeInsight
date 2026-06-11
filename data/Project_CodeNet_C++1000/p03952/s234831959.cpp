#include <bits/stdc++.h>

#include <set>
#include <iterator>
using namespace std;
// using namespace __gnu_pbds;


#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define INF (ll)1e17
#define matrix vector<vector<ll> >

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )
#define maxbits 9
#define maxmask (1ll<<maxbits)
// typedef tree<pll, null_type, less<pll>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
const int  N=2e5 +10, M=(ll)1e9+1 ;
const int mod =(ll)998244353 ,sz=5, MAX=(ll)1e6+10;
string fir="Monocarp",sec="Bicarp";
	
void work(){
	ll n,x;
	cin >> n >> x;
	if(n==1){
		if(x==1)
			cout << "Yes\n" << 1 ;
		else
			cout << "No";
	}
	else if(n==2){
		if(x==2)
			cout << "Yes\n" << "1\n2\n3" ;
		else
			cout << "No";
	}
	else{
		if(x==1 || x==2*n-1) 
			cout << "No";
		else{
			cout << "Yes\n";
			map<ll,ll> m;
			m[x]=m[x+1]=m[x-1]=1;
			ll cur=1;
			if(x==2)
				m[x+2]=1;
			else 
				m[x-2]=1;

			for(ll i=1;i<=n-2;i++){
				while(m[cur]==1){
					cur++;
				}
				m[cur]=1;
				cout << cur << "\n";
			}
			if(x==2)
				cout << x+1 << "\n" << x << "\n" << x-1 << "\n" << x+2 << "\n";
			else
				cout << x-1 << "\n" << x << "\n" << x+1 << "\n" << x-2 << "\n";
			for(ll i=1;i<=2*n-1;i++){
				if(m[i]!=1)
					cout << i << "\n";
			}
		}
	}
  	return;

} 
int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);

	
	ll t;
	// cin >> t;
	t=1;
	while(t--){
	        work();
	}
return 0;
}
