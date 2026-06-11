#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111



	void solve(){


		ini(x0,y0,x1,y1);
		string tmp;
		int tmp1 = 0;
		tmp1+=y1-y0;
		while(tmp1--)tmp+='U';
		tmp1=x1-x0;
		//out(1,tmp1);
		while(tmp1--)tmp+='R';
		tmp1=y1-y0;
		while(tmp1--)tmp+='D';
		tmp1=x1-x0;
		while(tmp1--)tmp+='L';
		tmp+='L';
		tmp1=y1-y0;
		tmp1++;
		//out(2,tmp1);
		while(tmp1--)tmp+='U';
		tmp1=x1-x0;
		tmp1++;
		while(tmp1--)tmp+='R';
		tmp+='D';
		tmp+='R';
		tmp1=y1-y0;
		tmp1++;
		while(tmp1--)tmp+='D';
		tmp1=x1-x0;
		tmp1++;
		while(tmp1--)tmp+='L';
		tmp+='U';
	out(tmp);







	}	























int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}
