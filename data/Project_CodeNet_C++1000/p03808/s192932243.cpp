#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<ll> b(n); //b[i] = a[i]-a[i+1]
	for(int i = 0; i < n; i++){
		if(i==n-1)b[i] = a[n-1]-a[0];
		else b[i] = a[i]-a[i+1];
	}

	ll sum=accumulate(all(a),(ll)0);
	if(2*sum % (n*(n+1)) != 0){
		cout << "NO" << endl;
		return 0;
	}

	ll cnt = 2*sum / (n*(n+1));

	vector<ll> c(n,-cnt);
	ll res = 0;
	for(int i = 0; i < n; i++){
		if(c[i]-b[i]<0 && (c[i]-b[i]) % n == 0) res += abs((c[i]-b[i])/n);
	}

	cout << (res==cnt?"YES":"NO")<<endl;

	return 0;
}