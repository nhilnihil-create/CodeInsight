#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
	int N; cin >> N;
	vector<int> T(N),A(N);
	rep(i,N) cin >> T[i];
	rep(i,N) cin >> A[i];
	vector<int> kari(N);
	vector<int> kaku(N);
	int now = 0;
	rep(i,N){
		if(T[i] != now){
			kaku[i] = T[i];
		}
		else kari[i] = T[i];
		now = T[i];	
	}

	now = 0;
	for(int i = N-1; i >= 0; i--){
		if(A[i] != now){
			if(kaku[i] != 0){
				if(kaku[i] != A[i]){
					cout << 0 << endl;
					return 0;
				}
			}
			else{
				kaku[i] = A[i];
				kari[i] = 0;
			}
		}
		else{
			if(kaku[i] != 0){
				if(kaku[i] > A[i]){
					cout << 0 << endl;
					return 0;
				}
			}
			else{
				kari[i] = min(kari[i],A[i]);
			}
		}
		now = A[i];
	}
	ll ans = 1;
	rep(i,N){
		//cout << kari[i] << endl;
		if(kari[i] != 0){
			ans *= kari[i];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}

