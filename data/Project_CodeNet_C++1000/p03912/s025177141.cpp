#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 0x3fffffff;


int main(){
	//ios_base::sync_with_stdio(0);
	int N, M;
	int nx[100005]={}, X[100005], mX[100005];
	int cx[100005]={}, ax[100005]={};

	cin >> N >> M;
	rep(i,N){
		cin >> X[i];
		nx[X[i]]++;
		mX[i] = X[i] % M;
	}
	rep(i,100005){
		cx[i%M] += nx[i]%2;
		ax[i%M] += nx[i]/2;
	}
//	rep(i,M+1){
		//cout << i << " : " << cx[i] << " " << ax[i] << endl;
//	}

	ll ans = 0;
	rep(i,M){
		int j = (M-i)%M;
		//cout << "j" <<  j << endl;
		if( j<i ){
			continue;
		}else if( i==j ){
			//cout << "i=j " << i << endl;
			ans += ax[i];
			ans += cx[i] / 2;
		}else{
			//cout << "i=" << i << " j=" << j << endl;
			int oi = i;
			if( cx[i] < cx[j] ) swap(i,j);
			ans += ax[i];
			int d = cx[i] - cx[j];
			ans += cx[j];
			if( ax[j]*2 >= d ){
				ans += ax[j] + d/2;
			}else{
				ans += ax[j]*2;
			}
			i = oi;
		}
		//cout << ans << endl;
	}

	cout << ans << endl;

	return 0;
}
