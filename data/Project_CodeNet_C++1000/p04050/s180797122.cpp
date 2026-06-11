#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define read(x) scanf("%d",&x)
int n,m;
int a[100005];
vector<int> ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	REP(i,m) cin>>a[i];
	int cnt_odd=0;
	REP(i,m) if (a[i]&1) ++cnt_odd;
	if (cnt_odd>2){
		cout<<"Impossible";return 0;
	}
	if (n==1){
		cout<<1<<endl<<1<<endl<<1<<endl;return 0;
	}
	if (m==1){
		cout<<a[1]<<endl;
		cout<<2<<endl;cout<<1<<' '<<a[1]-1<<endl;
		return 0;
	}
	if (cnt_odd==1){
		REP(i,m) if (a[i]&1){
			cout<<a[i];
			ans.pb(a[i]+1);
		}
		REP(i,m) if (!(a[i]&1)){
			cout<<' '<<a[i];
			ans.pb(a[i]);
		}
		cout<<endl;
		ans[ans.size()-1]--;
	}
	if (cnt_odd==0){
		ans.pb(1);
		REP(i,m){
			cout<<a[i]<<' ';
			ans.pb(a[i]);
		}
		cout<<endl;
		ans[ans.size()-1]--;
	}
	if (cnt_odd==2){
		REP(i,m) if (a[i]&1){
			if (cnt_odd==2){
				cout<<a[i];ans.pb(a[i]+1);--cnt_odd;
			}
			else{
				swap(a[i],a[m]);
			}
		}
		REP(i,m) if (!(a[i]&1)){
			cout<<' '<<a[i];ans.pb(a[i]);
		}
		cout<<' '<<a[m]<<endl;if (a[m]>1) ans.pb(a[m]-1);
	}
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();++i) cout<<ans[i]<<' ';
	return 0; 
}