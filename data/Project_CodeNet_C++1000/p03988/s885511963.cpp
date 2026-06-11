#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;

string yes = "Possible\n";
string no = "Impossible\n";
ll n;
ll a[2002];
ll used[2002];
int main()
{
	cin >> n;
	for(ll i=1;i<=n;i++) cin >> a[i];

	sort(a+1,a+n+1);

	if(n == 2) {
		cout << yes; return 0;
	}
	if(a[n]==2){
		if(a[1]==1 && a[2]==2) {
			cout << yes;
		}else cout << no;
		return 0;
	}
	multiset<ll> S;
	ll d = a[n];
	for(ll i = d ; i > (d/2) ; i--) S.insert(i);
	for(ll i = ((d+1)/2) ; i <= d ; i++) S.insert(i);

	for(auto it : S) {
		bool ok = false;
		for(ll i=1;i<=n;i++){
			if(used[i] == 0 && a[i] == it){
				used[i]=1;
				ok=true;
				break;
			}
		}
		if(ok==false) {
			cout<<no; return 0;
		}
	}
	ll maxm = (d + 1) / 2;
	for(ll i=1;i<=n;i++){
		if(used[i]==0 && a[i] < maxm + 1) {
			cout << no; return 0;
		}
	}
	cout << yes;
	return 0;
}