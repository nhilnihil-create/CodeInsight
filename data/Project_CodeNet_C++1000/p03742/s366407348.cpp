#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
const ll INF=1e9+7;
const ll N = 100001;
ll x,y;

int main(){
	cin>>x>>y;
	if(abs(x-y)<2) cout<<"Brown"<<endl;
	else cout<<"Alice"<<endl;
	return 0;
}