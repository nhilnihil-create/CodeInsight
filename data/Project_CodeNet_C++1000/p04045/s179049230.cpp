#include <bits/stdc++.h>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;

const int N = 1e7 + 12;
const ll mod = 1e9 + 7;

int n, m;
bool gd[N], was[N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1, x;i <= m;i++)
		cin >> x, gd[x] = 1;
	queue<int> q;
	q.push(0);
	was[0] = 1;
	while(q.size()){
		int v = q.front();
		if(v >= n){
			cout << v;
			exit(0);
		}
		q.pop();
		for(int i = 0;i <= 9;i++){
			if(gd[i])
				continue;
			if(!was[v * 10 + i]){
				was[v * 10 + i] = 1;
				q.push(v * 10 + i);	
			}
		}
	}
}
