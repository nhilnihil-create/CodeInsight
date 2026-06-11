#include <bits/stdc++.h>

using namespace std;

template <class T>
using lim = numeric_limits<T>;

typedef long long ll;
typedef long double ld;

const int maxN = 50;

ll combi[maxN+1][maxN+1];

// compute combination until maxN
void computeCombi(){
	memset(combi, 0, sizeof combi);
	
	for (int i = 0; i <= maxN; i++){
		combi[i][0] = 1;
	}
	
	for (int i = 1; i <= maxN; i++){
		for (int j = 1; j <= maxN; j++){
			combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
		}
	}
}


int computed[maxN*maxN+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	computeCombi();
	
	int n, a, b;
	cin >> n >> a >> b;
	ll v[n];
	
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	sort(v, v+n, greater<ll>());
	
	
	ll totalA = v[0];
	// distinct numbers in first a
	vector<ll> unique;
	unique.push_back(v[0]);
	
	// count of numbers in first a
	unordered_map<int, int> countInA;
	countInA[v[0]] = 1;
	for (int i = 1; i < a; i++){
		totalA += v[i];
		if (v[i]!=v[i-1]) unique.push_back(v[i]);
		countInA[v[i]]++;
	}
	
	ld mean = (ld) totalA / a;
	
	unordered_map<int, int> counters;
	for (int i = 0; i < n; i++){
		counters[v[i]]++;
	}

	ll ways;
	int size = unique.size();
	// increase size until it's not all same
	if (size==1){	
		ways = 0;
		for (int i = a; i <= min(counters[v[0]],b); i++){
			ways += combi[counters[v[0]]][i];
		}
	}
	// how many ways to get this specific sequence
	else {
		ways = 1;
		for (ll num : unique){
			ways *= combi[counters[num]][countInA[num]];
		}
	}
	
	cout << fixed << setprecision(6) << mean << endl;
	cout << ways << endl;
}
