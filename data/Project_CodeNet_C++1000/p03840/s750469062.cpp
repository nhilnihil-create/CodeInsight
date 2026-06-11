#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;
const int mod1=998244353;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll ai,ao,at,aj,al,as,az;cin >> ai >> ao >> at >> aj >> al >> as >> az;
	ll ans=ao;
	if(aj%2==1 && al%2==1){
		if(ai>=1){
			ai--;
			aj--;
			al--;
			ans+=3;
		}
	}
	else if(ai%2==1 && aj%2==1 && al>0){
		ai--;
		aj--;
		al--;
		ans+=3;
	}
	else if(ai%2==1 && al%2==1 && aj>0){
		ai--;
		aj--;
		al--;
		ans+=3;
	}
	ans+=ai/2*2+aj/2*2+al/2*2;
	cout << ans << endl;
}