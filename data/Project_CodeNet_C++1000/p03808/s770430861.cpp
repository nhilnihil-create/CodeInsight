#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a.at(i);
	ll sum=0;
	rep(i,n) sum+=a.at(i);
	if(sum%(n*(n+1)/2)!=0){
		cout << "NO" << endl;
		return 0;
	}
	ll k=sum/(n*(n+1)/2);
	vector<ll> b(n);
	rep(i,n-1) b.at(i)=a.at(i+1)-a.at(i);
	b.at(n-1)=a.at(0)-a.at(n-1);
	rep(i,n){
		if(b.at(i)>k || (k-b.at(i))%n!=0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}