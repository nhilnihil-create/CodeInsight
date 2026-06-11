#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

ll gcd(ll a,ll b){
	return a%b==0? b:gcd(b,a%b);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<bool> a(n+1);
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=i;
		a.at(i)=true;
		if(sum>=n){
			a.at(sum-n)=false;
			break;
		}
	}
	rep(i,n+1){
		if(a.at(i)) cout << i << endl;
	}
}