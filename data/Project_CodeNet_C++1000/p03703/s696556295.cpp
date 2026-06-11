#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX 200000

int n, bit[MAX+2], bit_size;

int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=(i&-i);
	}
	return s;
}

void add(int i, int x){
	while(i<=bit_size){
		bit[i]+=x;
		i+=(i&-i);
	}
	return;
}

int main(){
	ll k;
	cin >> n >> k;
	vector<ll> s(n+1, 0);
	for(int i=1; i<=n; i++){
		ll a;
		cin >> a;
		s[i]=s[i-1]+a-k;
	}

	vector<ll> v=s;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i=0; i<=n; i++){
		s[i]=lower_bound(v.begin(), v.end(), s[i])-v.begin()+1;
	}

	bit_size=v.size();
	ll ans=0;
	for(int i=0; i<=n; i++){
		ans+=sum(s[i]);
		add(s[i], 1);
	}
	cout << ans << endl;
	return 0;
}