#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define all(t) (t).begin(),(t).end()
#define MOD 1000000007
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int main(){
	int n;
	cin >> n;
	int p[20010];
	FOR(i,n)cin >> p[i];
	for(int i=1;i<=n;i++){
		cout << i*(n+1);
		if(i!=n)cout << " ";
	}
	cout << endl;
	int ans[20010];

	for(int i=n;i>0;i--){
		ans[n-i]=i*(n+1);
	}
	FOR(i,n){
		ans[p[i]-1]+=i;
	}
	FOR(i,n){
		cout << ans[i];
		if(i!=n-1)cout << " ";
	}
	cout << endl;
}