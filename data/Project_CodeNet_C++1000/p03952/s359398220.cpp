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
	int n,x;
	cin >> n >> x;
	if(x==1 || x==2*n-1){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
		int ans[200010];
		if(x==2*n-2){
			vector<int> v;
			for(int i=1;i<=2*n-1;i++){
				if(i!=x && i!=2*n-1)v.push_back(i);
			}
			ans[n-1]=2*n-1;
			ans[n-2]=x;
			int cnt=0;
			FOR(i,2*n-1){
				if(i!=n-1 && i!=n-2){
					ans[i]=v[cnt];
					cnt++;
				}
			}
		}else{
			vector<int> v;
			for(int i=1;i<=2*n-1;i++){
				if(i!=x && i!=x+1 && i!=x+2 && i!=1)v.push_back(i);
			}
			ans[n-1]=1;
			ans[n-2]=x;
			ans[n-3]=x+1;
			ans[n]=x+2;
			int cnt=0;
			FOR(i,2*n-1){
				if(i!=n-1 && i!=n-2 && i!=n-3 && i!=n){
					ans[i]=v[cnt];
					cnt++;
				}
			}
		}
		FOR(i,2*n-1){
			cout << ans[i] << endl;
		}
	}
}