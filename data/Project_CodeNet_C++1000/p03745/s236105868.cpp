#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	ll ans = 1;
	for(int i = 1; i + 1 < n; i++) {
		if (a[i - 1] <= a[i] && a[i] <= a[i + 1]){
			i++;
			while(i + 1 < n){
				if ((a[i - 1] <= a[i] && a[i] <= a[i + 1])){
					i++;
				}
				else{
					ans++;
					break;
				}
			}
		}
		else if (a[i - 1] >= a[i] && a[i] >= a[i + 1]){
			i++;
			while(i + 1 < n){
				if(a[i - 1] >= a[i] && a[i] >= a[i + 1]){
					i++;
				}
				else{
					ans++;
					break;
				}
			}
		}
		else{
			ans++;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}