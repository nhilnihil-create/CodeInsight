#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for(int i =0 ; i < n; ++i)
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair < int, int >
typedef vector<int> vi;
typedef  long long ll;
const int mod =1e9+7;
const int N = (int)2e5 + 5;

int used[101];
void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=a;i<=b;i++){
		used[i]++;
	}
	int cnt=0;
	for(int i=c;i<=d;i++){
		used[i]++;
		if(used[i]==2)cnt++;
	}		
	cout<<max(cnt-1,0);	

}

int main(){
	Red;
	int t=1;
	// cin>>t;
	while(t--)
	solve();
	return 0;
}