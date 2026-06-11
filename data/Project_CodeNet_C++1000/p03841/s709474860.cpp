#include <bits/stdc++.h>
using namespace std;
const int maxn = 511;
int a[maxn * maxn], esp[maxn * maxn];
int main(){
	auto bad = [](){
		cout << "No" << endl;
		exit(0);
	};
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		if(a[x]) bad();
		a[x] = i;
		esp[x] = 1;
	}
	queue<int> q;
	for(int i = 1; i <= n * n; i++){
		if(a[i]){
			for(int j = 1; j < a[i]; j++){
				if(q.empty()) bad();
				int p = q.front(); q.pop();
				a[p] = a[i];
			}
		} else {
			q.push(i);
		}
	}
	while(!q.empty()) q.pop();
	for(int i = n * n; i >= 1; i--){
		if(esp[i]){
			for(int j = 1; j <= n - a[i]; j++){
				if(q.empty()) bad();
				int p = q.front(); q.pop();
				a[p] = a[i];
			}
		} else if(!a[i]){
			q.push(i);
		}
	}
	cout << "Yes" << endl;
	for(int i = 1; i <= n * n; i++) cout << a[i] << " \n"[i == n * n];
	return 0;
}

