#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[101010];
ll n, s, k, c;

void die() { cout << "NO" << endl; exit(0); }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, t;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
		s += A[i];
	}
	
	k = s / (n * (n + 1) / 2);
	
	if(!k || s % k != 0) die();
	
	for(i=0; i<n; i++){
		t = A[i] + k - A[(i + 1) % n];
		if(t < 0 || t % n != 0) die();
		c += t / n;
	}
	
	if(c != k) die();
	
	cout << "YES" << endl;
	
	return 0;
}