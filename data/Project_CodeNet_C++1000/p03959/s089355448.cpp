#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[100010],b[100010];
bool A[100010];
int main() {
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	A[0]=true;
	for(int i=1;i<n;i++){
		if(a[i-1]!=a[i]){
			A[i]=true;
		}
	}
	if(A[n-1]==true&&a[n-1]!=b[n-1]){
		cout << 0;
		return 0;
	}	
	A[n-1]=true;
	for(int i=n-2;i>=0;i--){
		if(b[i]!=b[i+1]){
			if(A[i]==true){
				if(a[i]!=b[i]){
					//cout << i<<endl<<b[i]<< " "<< b[i+1]<<endl;
					cout << 0;
					return 0;
				}
			}
			if(a[i]<b[i]){
				cout << 0;
				return 0;
			}
			A[i]=true;
		}
	}
	ll ans=1;

	for(int i=0;i<n;i++){
		if(A[i]!=true){
			ans*=min(b[i],a[i]);
			ans%=inf;
		}
	}
	cout << ans;
	return 0;
}