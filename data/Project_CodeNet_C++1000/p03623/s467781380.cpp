/*Flamenco Sketches*/
#include<bits/stdc++.h>
using namespace std;
 
#define NL '\n'
#define xx first
#define yy second
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define async() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 
//#define FayeValentine 
void dbg(){cerr<<NL;}template<typename H,typename... T> void dbg(H h,T... t){cerr<<' '<<h;dbg(t... );}
#ifdef  FayeValentine
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",dbg(__VA_ARGS__)
#else
#define debug(...) 
#endif


void absinthe() {
	int x, a, b; cin >> x >> a >> b; 
	if(abs(x-a) < abs(x-b)) cout << 'A' << NL;
	else cout << 'B' << NL; 
}
 
 
int main(){
  //freopen("input.txt", "r", stdin);
  async();
  int __t = 1; //cin >> __t;
  for(int __c = 1; __c <=__t; __c++) {
    //cout << "Case #" << __c << ": "; 
    absinthe();
  }
}  