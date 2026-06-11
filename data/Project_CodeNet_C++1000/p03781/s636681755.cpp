#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,-1,0,1},dy={1,0,-1,0};
vector<int> b={'a','i','u','e','o'};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x;cin >> x;
	int ans=0,n=0;
	for(int i=1;n<x;++i){
		n+=i;
		ans++;
	}
	cout << ans << endl;
}