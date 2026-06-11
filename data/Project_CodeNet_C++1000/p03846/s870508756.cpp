#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define N  100000
#define mod 1000000007


typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

ll power(int x,int y){
    if(y==0)	return 1LL;
	if(y==1)	return x%mod;
	ll m = power(x, y/2);
	if(y%2)	return (m*m%mod)*x%mod;
	return (m*m)%mod;
	}
	
int main() {
	fast;
	int n;
	cin>>n;
	vector<int> a(n);
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if((a[i]%2==0 && n%2!=1) || a[i]>(n-1)){
			cout<<0;
			return 0;
			}
		if (m.find(a[i]) == m.end()) m[a[i]]=1;
		else if(m[a[i]]==1) m[a[i]]++;
		else if(m[a[i]]==2){
			cout<<0;
			return 0;
			}
		}
	if(n%2==1 && m[0]==2) cout<<0;
	else{
		cout<<power(2,(n/2));
		}
	
}
