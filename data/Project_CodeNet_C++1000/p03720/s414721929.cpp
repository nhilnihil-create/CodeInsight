#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

	int count[n+2];
	memset(count, 0, sizeof count);

	while (m--){
		int a,b;
		cin >> a >> b;
		count[a]++;
		count[b]++;
	}

	for (int i = 1; i <= n; i++){
		cout << count[i] << endl;
	}

	return 0;
}