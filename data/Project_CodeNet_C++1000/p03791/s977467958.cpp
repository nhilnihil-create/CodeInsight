#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll can[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int c=0;
	int e=0;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
// 		cout<<c<<" "<<(i-c-1)*2+1<<" "<<e<<endl;
		while ((i-c-1)*2+1>e){
			c++;
		}
// 		cout<<c<<" "<<(i-c-1)*2+1<<" "<<e<<endl;
// 		cout<<c+1<<endl;
		can[i]=c+1;
		e=x;
	}
	ll v=1;
	ll t=0;
	for (int i=n-1;i>=0;i--){
		v*=(ll)(n-can[i]+1ll-t);
		v%=mod;
		t++;
	}
	cout<<v<<endl;
}