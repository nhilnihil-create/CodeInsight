#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define out return 0
#define pii pair<ll,ll>
#define ll long long int
using namespace std;
ll mn=1e18,mx=-1e18;
const ll mv=1000005;
ll n,l,a[mv],sum,ch,f,b;
vector<ll> ans;
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin>>n>>l;
	b=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		if(a[i]+a[i+1]>=l){
			f=i;
			ch=1;
			break;
		}
	}
	if(!ch){
		cout<<"Impossible";
		out;
	}
	cout<<"Possible\n";
	for(int i=1;i<=f;i++){
		cout<<i<<"\n";
	}
	for(int i=n-1;i>=f+1;i--){
		cout<<i<<"\n";
	}
}