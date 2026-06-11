#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100100],res;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		res+=a[i]/2;
		a[i]%=2;
		if(a[i]&&a[i-1]){
			a[i]--;
			a[i-1]--;
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
