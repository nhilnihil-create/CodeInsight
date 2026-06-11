#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int a,b,c,d,e,f;
void solve(){
	cin >> a >> b >> c >> d >> e >> f;
	a*=100; b*=100;
	
	int ans = a, ans2 = 0;
	for(int i = 0; i <= f; i+=a){
		for(int j = i; j <= f; j+=b){
			for(int ii = 0; ii+j <= f; ii+=c){
				for(int jj = ii; jj+j <= f; jj+=d){
					if(jj*100 > j*e) break;
					if(ans*jj > (jj+j)*ans2){
						ans = jj+j;
						ans2 = jj;
					}
				}
			}
		}
	}
	cout << ans << " " << ans2 << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}