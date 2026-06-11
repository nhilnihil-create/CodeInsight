#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> a){
	sort(a.begin(), a.end());
	int d = a.front() * 2;
	if(a[0] == a[1]) d -= 1;
	if((int)a.size() > 2 && a[0] == a[2]) return false;
	if(a[(int)a.size() - 1] != d) return false;
	if(a[(int)a.size() - 2] != d) return false;
	for(int i = 0; i + 1 < (int)a.size(); i++){
		if(a[i] + 1 < a[i+1]) return false;
	}
	for(int i = 0; i + 2 < (int)a.size(); i++){
		if(a[i+1] != a[i] && a[i+1] != a[i+2]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << (solve(a) ? "Possible" : "Impossible") << '\n';
}