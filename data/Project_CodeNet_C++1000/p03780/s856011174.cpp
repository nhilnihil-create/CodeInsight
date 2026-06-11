#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX 5000

int n, k;
ll a[MAX];

bool need(int p){
	vector<ll> v;
	v.push_back(0);
	for(int i=0; i<n; i++){
		if(i!=p) v.push_back(a[i]);
	}

	bool b[n][k+1];
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			if(j==0) b[i][j]=true;
			else b[i][j]=false;
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<=k; j++){
			b[i][j]=b[i-1][j];
		}
		for(int j=0; j<=k; j++){
			if(j+v[i]<=k){
				b[i][j+v[i]]|=b[i-1][j];
			}
		}
	}

	for(int j=max(k-a[p], 0ll); j<k; j++){
		if(b[n-1][j]) return true;
	}
	return false;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);

	int l=-1, r=n;
	while(r-l>1){
		int m=(l+r)/2;
		if(need(m)) r=m;
		else l=m;
	}
	cout << r << endl;
	return 0;
}