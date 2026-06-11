#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

bool ext(int x, int y, int z){
	if(x<y&&y>z) return true;
	if(x>y&&y<z) return true;
	return false;
}

int main(void) {
	int n; cin >> n;
	vi a(n); rep(i,n) cin >> a[i];
	int ans = 1;
	int i=0;
	while(i<n-1){
		while(i<n-1&&a[i]==a[i+1])i++;
		if(a[i]<a[i+1]){
			while(i<n-1&&a[i]<=a[i+1])i++;
			if(i==n-1) break;			
			ans++;
			i++;
//			cout << i << endl;
			continue;
		}
		if(a[i]>a[i+1]){
			while(i<n-1&&a[i]>=a[i+1])i++;
			if(i==n-1) break;
			ans++;
			i++;
//			cout << i << endl;			
			continue;
		}		
	}
	cout << ans << endl;
}
