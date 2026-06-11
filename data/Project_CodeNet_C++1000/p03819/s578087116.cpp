# include <bits/stdc++.h>
# define sz(a) int(a.size())
# define vec vector  
# define pb push_back

const int Sz = (int)3e5 + 2;

using namespace std;

int ans[Sz];       
int n, m;

int l[Sz], r[Sz];
vec<int> add[Sz], del[Sz];


struct fenwick {
	int n;
	vec<int> t;
	fenwick (int n) : n(n), t(n + 1) {}

  void add (int id, int x) {
  	for (int i = id; i >= 1; i -= (i & (-i)))
  		t[i] += x;
  }
  int get (int id) {
  	int res = 0;
  	for (int i = id; i <= n; i  += (i & (-i)))
  		res += t[i];   
  	return res;
  }    
};

inline void Read_rap() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
}	

int main()
{
	Read_rap();            
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		add[l[i]].pb(i);
		del[r[i]].pb(i);
	}        

	fenwick T(m);
	vec<int> dv[m + 1];
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j += i)
			dv[j].pb(i);                             

	for (int i = 1; i <= m; i++) {
		for (int j : add[i]) {
			T.add(r[j], +1);
		}                  

		for (int d : dv[i]) {
			ans[d] += T.get(i) - T.get(i + d);
		}	      
		                    
		for (int j : del[i]) {
			T.add (r[j],-1);
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << endl;
				
			
	return 0;
}