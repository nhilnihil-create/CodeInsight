# include <bits/stdc++.h>

# define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
# define FORD(i, a, b) for(int i = (a); i >= (b); --i)
# define VAR(v, i) __typeof(i) v=(i)
# define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define ff first
# define ss second
# define mp make_pair
# define pb push_back
# define next ____next
# define prev ____prev
# define left ____left
# define hash ____hash

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

// ---------------------------------------------------------------------------------------------------------------------------------- //

# define MOD 1000000007LL
# define MAXN 100009

int N;
lld arr[MAXN];
lld yerler[MAXN];

lld ans = 1;

int main(){
	cin >> N;
	
	
	FOR(i, 1, N){
		cin >> arr[i];
		
		//~ arr[i] = arr[i] / 2 - (i - 1);
		yerler[i] = (i-1) * 2 + 1;
	}
	
	lld giden = 0;
	lld sana = 0;
	int pnt = 0;
	
	while(pnt != N){
		while(pnt != N  &&  yerler[pnt+1] - 2LL * giden <= arr[pnt+1]){
			sana++;
			pnt++;
		}
		
		if(pnt != N){
			pnt++;
			sana++;
		}
		
		ans = (ans * sana) % MOD;
		
		sana--;
		giden++;
		
		//~ cout << ans << " " << sana << " " << pnt << "\n";
		//~ getchar();
	}
	
	while(sana){
		ans = (ans * sana) % MOD;
		sana--;
	}
	
	cout << ans << "\n";
}
