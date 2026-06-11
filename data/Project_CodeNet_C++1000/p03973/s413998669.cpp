#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define all(n) (n).begin(),(n).end()
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}


int main(){
	ll n;
	cin >> n;
	ll a[100010];
	FOR(i,n)cin >> a[i];

	ll ans=a[0]-1;
	a[0]=1;
	ll cnt=2;
	for(int i=1;i<n;i++){
		if(a[i]==cnt)cnt++;
		if(a[i]>cnt){
			if(a[i]%cnt==0){
				ans+=a[i]/cnt-1;
				a[i]=cnt;
				
			}else{
				ans+=a[i]/cnt;
				a[i]=a[i]%cnt;
			}
		}
	}
	cout << ans << endl;
}