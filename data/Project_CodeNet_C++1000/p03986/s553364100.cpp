#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	string x;cin>>x;
	int n=x.size(),tnt=0,ans=n;
	for(int i=n-1;i>=0;i--){
		if(x[i]=='T') tnt++;
		else if(x[i]=='S'&&tnt>0){
			tnt--;
			ans-=2;
		}
	}

	cout<<ans<<"\n";
}