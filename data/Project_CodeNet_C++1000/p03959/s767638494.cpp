#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;

int main(){
	int n; cin >> n;
	vector<int> t(n),a(n);
	ll ans=1;
	for(int i=0;i<n;i++){
		cin >> t[i];
	}
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(t[n-1]!=a[0]){
		cout << 0 << endl;
		return 0;
	}
	else{
		for(int i=1;i<n-1;i++){
			if(t[i]<t[i-1]||a[i]>a[i-1]){
				cout << 0 << endl;
				return 0;
			}
			if(t[i]>t[i-1]&&a[i]>a[i+1]&&t[i]!=a[i]){
				cout << 0 << endl;
				return 0;
			}
			if(t[i]==t[i-1]&&a[i]>a[i+1]&&a[i]>t[i]){
				cout << 0 << endl;
				return 0;
			}
			if(a[i]==a[i+1]&&t[i]>t[i-1]&&a[i]<t[i]){
				cout << 0 << endl;
				return 0;
			}
			if(t[i]==t[i-1]&&a[i]==a[i+1]){
				ans*=min(t[i],a[i]);
				ans%=mod;
			}
		}
	}
	cout << ans << endl;
}